#ifdef _WIN32
// Required due to some headers using WinSock2.h
// & some headers requiring windows.h
// If this was not here, a link conflict would emerge due to
// windows.h including winsock1
#include <WinSock2.h>
#endif

#include "ops_sqfvm.h"
#include "../runtime/runtime.h"
#include "../runtime/type.h"
#include "../runtime/frame.h"
#include "../runtime/sqfop.h"
#include "../runtime/d_array.h"
#include "../runtime/d_boolean.h"
#include "../runtime/d_code.h"
#include "../runtime/d_scalar.h"
#include "../runtime/d_string.h"
#include "../runtime/diagnostics/stacktrace.h"
#include "../runtime/diagnostics/d_stacktrace.h"
#include "d_config.h"
#include "d_object.h"


#include <sstream>
#include <array>
#include <algorithm> 
#include <cctype>
#include <cmath>
#include <locale>

namespace err = logmessage::runtime;
using namespace sqf::runtime;
using namespace sqf::types;
using namespace std::string_literals;

namespace
{
    value assembly___code(runtime& runtime, value::cref right)
    {
        auto code = right.data<d_code>();
        
        std::vector<value> outarr;
        for (auto it = code->value().begin(); it != code->value().end(); it++)
        {
            outarr.push_back((*it)->to_string());
        }
        return outarr;
    }
    value assembly___string(runtime& runtime, value::cref right)
    {
        auto str = right.data<d_string>();
        auto set = runtime.parser_sqf().parse(runtime, *str);
        if (set.has_value())
        {
            std::vector<value> outarr;
            for (auto it = set->begin(); it != set->end(); it++)
            {
                outarr.push_back((*it)->to_string());
            }
            return outarr;
        }
        else
        {
            return {};
        }
    }
    value cmds___(runtime& runtime)
    {
        std::vector<value> outarr;
        auto str = "n";
        for (auto& pair = runtime.sqfop_nular_begin(); pair != runtime.sqfop_nular_end(); pair++)
        {
            outarr.push_back(std::vector<value> {
                str,
                pair->first.name
            });
        }
        str = "u";
        for (auto& pair = runtime.sqfop_unary_begin(); pair != runtime.sqfop_unary_end(); pair++)
        {
            outarr.push_back(std::vector<value> {
                str,
                pair->first.name,
                pair->first.right_type.to_string()
            });
        }
        str = "b";
        for (auto& pair = runtime.sqfop_binary_begin(); pair != runtime.sqfop_binary_end(); pair++)
        {
            outarr.push_back(std::vector<value> {
                str,
                pair->first.left_type.to_string(),
                pair->first.name,
                pair->first.right_type.to_string()
            });
        }
        return outarr;
    }
    value cmdsimplemented___(runtime& runtime)
    {
        std::vector<value> outarr;
        auto str = "n";
        for (auto& pair = runtime.sqfop_nular_begin(); pair != runtime.sqfop_nular_end(); pair++)
        {
            if (pair->second.description().empty())
                continue;
            outarr.push_back(std::vector<value> {
                str,
                pair->first.name
            });
        }
        str = "u";
        for (auto& pair = runtime.sqfop_unary_begin(); pair != runtime.sqfop_unary_end(); pair++)
        {
            if (pair->second.description().empty())
                continue;
            outarr.push_back(std::vector<value> {
                str,
                pair->first.name,
                pair->first.right_type.to_string()
            });
        }
        str = "b";
        for (auto& pair = runtime.sqfop_binary_begin(); pair != runtime.sqfop_binary_end(); pair++)
        {
            if (pair->second.description().empty())
                continue;
            outarr.push_back(std::vector<value> {
                str,
                pair->first.left_type.to_string(),
                pair->first.name,
                pair->first.right_type.to_string()
            });
        }
        return outarr;
    }
    value vm___(runtime& runtime)
    {
        std::vector<value> outarr;
        auto str = "n";
        for (auto& pair = runtime.sqfop_nular_begin(); pair != runtime.sqfop_nular_end(); pair++)
        {
            if (pair->first.name.length() < 2 || pair->first.name[pair->first.name.length() - 1] != '_' || pair->first.name[pair->first.name.length() - 2] != '_')
                continue;
            outarr.push_back(std::vector<value> {
                str,
                    pair->first.name
            });
        }
        str = "u";
        for (auto& pair = runtime.sqfop_unary_begin(); pair != runtime.sqfop_unary_end(); pair++)
        {
            if (pair->first.name.length() < 2 || pair->first.name[pair->first.name.length() - 1] != '_' || pair->first.name[pair->first.name.length() - 2] != '_')
                continue;
            outarr.push_back(std::vector<value> {
                str,
                    pair->first.name,
                    pair->first.right_type.to_string()
            });
        }
        str = "b";
        for (auto& pair = runtime.sqfop_binary_begin(); pair != runtime.sqfop_binary_end(); pair++)
        {
            if (pair->first.name.length() < 2 || pair->first.name[pair->first.name.length() - 1] != '_' || pair->first.name[pair->first.name.length() - 2] != '_')
                continue;
            outarr.push_back(std::vector<value> {
                str,
                    pair->first.left_type.to_string(),
                    pair->first.name,
                    pair->first.right_type.to_string()
            });
        }
        return outarr;
    }
    // value tree___string(runtime& runtime, value::cref right)
    // {
    //     auto str = right.as_string();
    //     std::stringstream sstream;
    //     runtime.parse_sqf_tree(str, &sstream);
    //     return sstream.str();
    // }
    // value tree___code(runtime& runtime, value::cref right)
    // {
    //     auto code = right.data<codedata>();
    //     auto str = code->tosqf();
    //     std::stringstream sstream;
    //     runtime.parse_sqf_tree(str, &sstream);
    //     return sstream.str();
    // }
    value help___string(runtime& runtime, value::cref right)
    {
        std::stringstream sstream;
        std::string str = *right.data<d_string>();
        bool wasfound = false;
        for (auto& pair = runtime.sqfop_nular_begin(); pair != runtime.sqfop_nular_end(); pair++)
        {
            if (pair->first.name != str)
                continue;
            auto cmd = pair->second;
            if (cmd.description().empty())
            {
                sstream << "NULAR '" << pair->first.name << "'\t<" << pair->first.name << ">" << std::endl;
            }
            else
            {
                sstream << "NULAR '" << pair->first.name << "'\t<" << cmd.name() << ">\t" << cmd.description() << std::endl;
            }
            wasfound = true;
        }
        for (auto& pair = runtime.sqfop_unary_begin(); pair != runtime.sqfop_unary_end(); pair++)
        {
            if (pair->first.name != str)
                continue;
            auto cmd = pair->second;
            if (cmd.description().empty())
            {
                sstream << "UNARY '" << pair->first.name << "'\t<" << cmd.name() << " " << pair->first.right_type.to_string() << ">" << std::endl;
            }
            else
            {
                sstream << "UNARY '" << pair->first.name << "'\t<" << cmd.name() << " " << pair->first.right_type.to_string() << ">\t" << cmd.description() << std::endl;
            }
            wasfound = true;
        }
        for (auto& pair = runtime.sqfop_binary_begin(); pair != runtime.sqfop_binary_end(); pair++)
        {
            if (pair->first.name != str)
                continue;
            auto cmd = pair->second;
            if (cmd.description().empty())
            {
                sstream << "BINARY '" << pair->first.name << "'\t<" <<
                    pair->first.left_type.to_string() << " " << cmd.name() << " " << pair->first.right_type.to_string() << ">" <<
                    std::endl;
            }
            else
            {
                sstream << "BINARY '" << pair->first.name << "'\t<" <<
                    pair->first.left_type.to_string() << " " << cmd.name() << " " << pair->first.right_type.to_string() << ">\t" <<
                    cmd.description() << std::endl;
            }
            wasfound = true;
        }
        if (!wasfound)
        {
            sstream << "Could not find any command with that name." << std::endl;
        }
        runtime.__logmsg(err::InfoMessage((*runtime.active_context().current_frame().current())->diag_info(), "HELP", sstream.str()));
        return {};
    }
    value configparse___string(runtime& runtime, value::cref right)
    {
        auto str = right.data<d_string, std::string>();
        runtime.parser_config().parse(runtime.confighost(), str);
        return {};
    }
    value allObjects__(runtime& runtime)
    {
        auto arr = std::make_shared<d_array>();
        for (auto& object : runtime.storage<object, object::object_storage>())
        {
            arr->push_back(object);
        }
        return value(arr);
    }
    value exit___(runtime& runtime)
    {
        runtime.exit(0);
        return {};
    }
    value exit___scalar(runtime& runtime, value::cref right)
    {
        runtime.exit(static_cast<int>(std::round(*right.data<d_scalar>())));
        return {};
    }
    value respawn___(runtime& runtime)
    {
        auto current = runtime.storage<object, object::object_storage>().player();
        if (current)
        {
            current->destroy(runtime);
        }
        auto root = runtime.confighost().root();
        auto cfgVehicles_ = root.navigate(runtime.confighost(), "CfgVehicles");
        sqf::runtime::confighost::config entry;
        if (cfgVehicles_.has_value())
        {
            auto caManBase_ = cfgVehicles_->navigate(runtime.confighost(), "CAManBase");
            if (caManBase_.has_value())
            {
                entry = *caManBase_;
            }
        }
        current = object::create(runtime, entry, false);
        runtime.storage<object, object::object_storage>().player(current);
        return current;
    }
    value preprocess___string(runtime& runtime, value::cref right)
    {
        auto content = right.data<d_string>();
        bool errflag = false;
        auto ppres = runtime.parser_preprocessor().preprocess(runtime, *content, { {}, "__preprocess__"s });
        if (errflag)
        {
            return {};
        }
        else
        {
            return ppres;
        }
    }
    value except___code_code(runtime& runtime, value::cref left, value::cref right)
    {
        class behavior_except : public frame::behavior
        {
        private:
            instruction_set m_set;
        public:
            behavior_except(instruction_set set) : m_set(set) {}
            virtual sqf::runtime::instruction_set get_instruction_set() override { return m_set; };
            virtual result enact(sqf::runtime::runtime& runtime, sqf::runtime::frame& frame) override { return result::exchange; };
        };
        frame f(
            runtime.default_value_scope(),
            {},
            right.data<d_code, sqf::runtime::instruction_set>(),
            {},
            std::make_shared<behavior_except>(left.data<d_code, sqf::runtime::instruction_set>()));
        runtime.active_context().push_frame(f);
        return {};
    }
    value callstack___(runtime& runtime)
    {
        auto context = runtime.active_context();
        std::vector<sqf::runtime::frame> stacktrace_frames(context.frames_rbegin(), context.frames_rend());
        sqf::runtime::diagnostics::stacktrace stacktrace(stacktrace_frames);
        return stacktrace;
    }
    value allfiles___array(runtime& runtime, value::cref right)
    {
        auto arr = right.data<d_array>();
        if (!arr->check_type(runtime, t_string(), 0, arr->size()))
        {
            return {};
        }
        auto files = std::vector<value>();
        auto fileio = runtime.fileio();
        // recursively search for pboprefix
        for (auto i = fileio.all_files_begin(); i != fileio.all_files_end(); ++i)
        {
            bool skip = true;
            for (auto& ext : *arr)
            {
                if (i->is_directory())
                {
                    break;
                }
                if (!(i->path().extension().compare(ext.data<d_string, std::string>())))
                {
                    skip = false;
                    break;
                }
            }
            if (!skip)
            {
                files.push_back(i->path().string());
            }
        }
        return files;
    }
    value pwd___(runtime& runtime)
    {
        auto path = std::filesystem::path((*runtime.active_context().current_frame().current())->diag_info().file);
        return std::filesystem::absolute(path).string();
    }
    value currentDirectory___(runtime& runtime)
    {
        auto path = std::filesystem::path((*runtime.active_context().current_frame().current())->diag_info().file);
        return std::filesystem::absolute(path.parent_path()).string();
    }
    value trim___(runtime& runtime, value::cref right)
    {
        auto str = right.data<d_string, std::string>();
        str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](int ch) {
            return !std::isspace(ch);
            }));
        str.erase(std::find_if(str.rbegin(), str.rend(), [](int ch) {
            return !std::isspace(ch);
            }).base(), str.end());
        return str;
    }
    value remoteConnect___(runtime& runtime, value::cref right)
    {
        if (!runtime.allow_networking())
        {
            runtime.__logmsg(err::NetworkingDisabled((*runtime.active_context().current_frame().current())->diag_info()));
            return false;
        }
        networking_init();
        if (runtime.is_networking_set())
        {
            runtime.__logmsg(err::AlreadyConnected((*runtime.active_context().current_frame().current())->diag_info()));
            return {};
        }
        auto s = right.as_string();
        auto index = s.find(':');
        if (index == std::string::npos)
        {
            runtime.__logmsg(err::NetworkingFormatMissmatch((*runtime.active_context().current_frame().current())->diag_info(), s));
            return {};
        }
        auto address = s.substr(0, index);
        auto port = s.substr(index + 1);
        SOCKET socket;
        if (networking_create_client(address.c_str(), port.c_str(), &socket))
        {
            runtime.__logmsg(err::FailedToEstablishConnection((*runtime.active_context().current_frame().current())->diag_info()));
            return false;
        }
        runtime.set_networking(std::make_shared<networking::client>(socket));
        return true;
    }
    value closeconnection___(runtime& runtime)
    {
        runtime.release_networking();
        return {};
    }
    value vmctrl___string(runtime& runtime, value::cref right)
    {
        auto str = right.data<d_string, std::string>();

        if (str == "abort")
        {
            runtime.execute(sqf::runtime::runtime::action::abort);
        }
        else if (str == "assembly_step")
        {
            runtime.execute(sqf::runtime::runtime::action::assembly_step);
        }
        else if (str == "leave_scope")
        {
            runtime.execute(sqf::runtime::runtime::action::leave_scope);
        }
        else if (str == "reset_run_atomic")
        {
            runtime.execute(sqf::runtime::runtime::action::reset_run_atomic);
        }
        else if (str == "start")
        {
            runtime.execute(sqf::runtime::runtime::action::start);
        }
        else if (str == "stop")
        {
            runtime.execute(sqf::runtime::runtime::action::stop);
        }
        else
        {
            // ToDo: Create custom log message for enum errors
            runtime.__logmsg(err::ErrorMessage((*runtime.active_context().current_frame().current())->diag_info(), "vmctrl", "exec unknown"));
        }
        return {};
    }
    value noBubble___ANY_CODE(runtime& runtime, value::cref left, value::cref right)
    {
        frame f = { right.data<d_code, instruction_set>() };
        f["_this"] = left;
        f.bubble_variable(false);
        runtime.active_context().push_frame(f);
        return {};
    }
    value noBubble___CODE(runtime& runtime, value::cref right)
    {
        frame f = { right.data<d_code, instruction_set>() };
        f["_this"] = {};
        f.bubble_variable(false);
        runtime.active_context().push_frame(f);
        return {};
    }
    //value provide___code_string(runtime& runtime, value::cref left, value::cref right)
    //{
    //    auto arr = right.data<d_array>();
    //    if (!arr->check_type(runtime, t_string(), 1, 3))
    //    {
    //        return {};
    //    }
    //    sqf::runtime::type ltype;
    //    sqf::runtime::type rtype;
    //    std::string name;
    //    int size = arr->size();
    //    switch (size)
    //    {
    //        case 1:
    //            name = arr->at(0).data<d_string, std::string>();
    //        break;
    //        case 3:
    //        {
    //            name = arr->at(1).data<d_string, std::string>();
    //            auto l = arr->at(0).data<d_string, std::string>();
    //            ltype = sqf::runtime::type::typemap().at(l);
    //            auto r = arr->at(arr->size() - 1).data<d_string, std::string>();
    //            rtype = sqf::runtime::type::typemap().at(r);
    //        }
    //        break;
    //        case 2:
    //        {
    //            name = arr->at(0).data<d_string, std::string>();
    //            auto r = arr->at(arr->size() - 1).data<d_string, std::string>();
    //            rtype = sqf::runtime::type::typemap().at(r);
    //        } break;
    //        default:
    //            return {};
    //    }
    //    switch (size)
    //    {
    //    case 1:
    //        sqf::commandmap::get().remove(name);
    //        sqf::commandmap::get().add(sqf::nulardata<std::shared_ptr<codedata>>(
    //            left.data<codedata>(),
    //            name,
    //            "",
    //            [](runtime& runtime, std::shared_ptr<codedata> code) -> value
    //            {
    //                code->loadinto(vm, runtime.active_vmstack());
    //                runtime.active_vmstack()->stacks_top()->set_variable("_this", value());
    //                return {};
    //            }));
    //        break;
    //    case 2:
    //        sqf::commandmap::get().remove(name, rtype);
    //        sqf::commandmap::get().add(sqf::unarydata<std::shared_ptr<codedata>>(
    //            left.data<codedata>(),
    //            name,
    //            rtype,
    //            "",
    //            [](runtime& runtime, std::shared_ptr<codedata> code, value::cref right) -> value
    //            {
    //                code->loadinto(vm, runtime.active_vmstack());
    //                runtime.active_vmstack()->stacks_top()->set_variable("_this", right);
    //                return {};
    //            }));
    //        break;
    //    case 3:
    //        sqf::commandmap::get().remove(ltype, name, rtype);
    //        sqf::commandmap::get().add(sqf::binarydata<std::shared_ptr<codedata>>(
    //            left.data<codedata>(),
    //            (short)4,
    //            name,
    //            ltype,
    //            rtype,
    //            "",
    //            [](runtime& runtime, std::shared_ptr<codedata> code, value::cref left, value::cref right) -> value
    //            {
    //                code->loadinto(vm, runtime.active_vmstack());
    //                runtime.active_vmstack()->stacks_top()->set_variable("_this", value({ left , right }));
    //                return {};
    //            }));
    //        break;
    //    }
    //    return {};
    //}
}
void sqf::operators::ops_sqfvm(sqf::runtime::runtime& runtime)
{
    using namespace sqf::runtime::sqfop;
    //add(unary("tree__", t_string(), "Returns a string containing the abstract syntax tree for the provided SQF expression.", tree___string));
    //add(unary("tree__", t_code(), "Returns a string containing the abstract syntax tree for the provided SQF expression.", tree___code));
    runtime.register_sqfop(nular("cmds__", "Returns an array containing all commands available.", cmds___));
    runtime.register_sqfop(nular("cmdsimplemented__", "Returns an array containing all commands that are actually implemented.", cmdsimplemented___));
    runtime.register_sqfop(unary("help__", t_string(), "Displays all available information for a single command.", help___string));
    runtime.register_sqfop(unary("configparse__", t_string(), "Parses provided string as config into a new config object.", configparse___string));
    // runtime.register_sqfop(binary(4, "merge__", t_config(), t_config(), "Merges contents from the right config into the left config. Duplicate entries will be overriden. Contents will not be copied but referenced.", merge___config_config));
    runtime.register_sqfop(nular("allObjects__", "Returns an array containing all objects created.", allObjects__));
    // runtime.register_sqfop(unary("pretty__", t_code(), "Takes provided SQF code and pretty-prints it to output.", pretty___code));
    // runtime.register_sqfop(unary("prettysqf__", t_code(), "Takes provided SQF code and pretty-prints it to output.", pretty___code));
    // runtime.register_sqfop(unary("prettysqf__", t_string(), "Takes provided SQF code and pretty-prints it to output.", prettysqf___string));
    runtime.register_sqfop(nular("exit__", "Exits the VM execution immediately. Will not notify debug interface when used.", exit___));
    runtime.register_sqfop(unary("vmctrl__", t_string(), "Executes the provided SQF-VM exection action.", vmctrl___string));
    runtime.register_sqfop(unary("exitcode__", t_scalar(), "Exits the VM execution immediately. Will not notify debug interface when used. Allows to pass an exit code to the VM.", exit___scalar));
    runtime.register_sqfop(nular("vm__", "Provides a list of all SQF-VM only commands.", vm___));
    runtime.register_sqfop(nular("respawn__", "'Respawns' the player object.", respawn___));
    runtime.register_sqfop(unary("preprocess__", t_string(), "Runs the PreProcessor on provided string.", preprocess___string));
    runtime.register_sqfop(unary("assembly__", t_code(), "returns an array, containing the assembly instructions as string.", assembly___code));
    runtime.register_sqfop(unary("assembly__", t_string(), "returns an array, containing the assembly instructions as string.", assembly___string));
    runtime.register_sqfop(binary(4, "except__", t_code(), t_code(), "Allows to define a block that catches VM exceptions. It is to note, that this will also catch exceptions in spawn! Exception will be put into the magic variable '_exception'. A callstack is available in '_callstack'.", except___code_code));
    runtime.register_sqfop(nular("callstack__", "Returns an array containing the whole callstack.", callstack___));
    runtime.register_sqfop(unary("allFiles__", t_array(), "Returns all files available in currently loaded paths with the given file extensions.", allfiles___array));
    runtime.register_sqfop(nular("pwd__", "Current path determined by current instruction.", pwd___));
    runtime.register_sqfop(nular("currentDirectory__", "Current directory determined by current instruction.", currentDirectory___));
    runtime.register_sqfop(unary("trim__", t_string(), "Trims provided strings start and end.", trim___));
    runtime.register_sqfop(unary("remoteConnect__", t_string(), "Connects this as a client to the provided endpoint. Endpoint is expected to have the format ADDRESS:PORT. Returns TRUE on success, false if it failed. Note that IP-Address is required, not DNS names (eg. use '127.0.0.1' instead of 'localhost').", remoteConnect___));
    runtime.register_sqfop(nular("closeConnection__", "Closes the connection previously opened using remoteConnect__.", closeconnection___));
    // runtime.register_sqfop(binary(4, "provide__", t_code(), t_array(), "Allows to provide an implementation for a given operator. Will NOT override existing definitions. Array is expected to be of the following formats: nular: [\"name\"], unary: [\"name\", \"type\"], binary: [\"ltype\", \"name\", \"rtype\"]", provide___code_string));
    runtime.register_sqfop(unary("noBubble__", t_code(), "Acts like call but disables bubbling of variables for the lower scope. (lower scope will have no access to upper scope variables)", noBubble___CODE));
    runtime.register_sqfop(binary(4, "noBubble__", t_any(), t_code(), "Acts like call but disables bubbling of variables for the lower scope. (lower scope will have no access to upper scope variables)", noBubble___ANY_CODE));
}