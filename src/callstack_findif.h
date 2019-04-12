#pragma once
#include <memory>
#include "callstack.h"
#include "arraydata.h"

namespace sqf
{
	class fordata;
	class codedata;
	class callstack_findif : public callstack
	{
	private:
		std::vector<std::shared_ptr<value>> m_input_vector;
		std::shared_ptr<codedata> m_codedata;
		size_t m_current_index;

	protected:
		::sqf::callstack::nextinstres do_next(sqf::virtualmachine* vm) override;

	public:
		callstack_findif(
			std::shared_ptr<sqf::sqfnamespace> ns,
			std::shared_ptr<codedata> exec,
			std::vector<std::shared_ptr<value>> arr
		) : callstack(ns),
			m_codedata(std::move(exec)),
			m_input_vector(arr),
			m_current_index(0)
		{
		}

		std::string get_name() override { return "findIf"; }
	};
}