#pragma once
#include <memory>
#include "callstack.h"
#include "arraydata.h"

namespace sqf
{
	class fordata;
	class codedata;
	class callstack_foreach : public callstack
	{
	private:
		std::vector<std::shared_ptr<sqf::value>> m_array;
		std::shared_ptr<codedata> m_codedata;
		size_t m_current_index;

	protected:
		::sqf::callstack::nextinstres do_next(sqf::virtualmachine* vm) override;

	public:
		callstack_foreach(
			std::shared_ptr<sqf::sqfnamespace> ns,
			std::shared_ptr<codedata> exec,
			std::vector<std::shared_ptr<sqf::value>> arr
		) :
			callstack(ns),
			m_array(std::move(arr)),
			m_codedata(std::move(exec)),
			m_current_index(0)
		{
		}

		std::string get_name() override { return "forEach"; }
	};
}