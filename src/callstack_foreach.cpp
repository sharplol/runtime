#include "callstack_foreach.h"
#include "virtualmachine.h"
#include "codedata.h"
#include "value.h"


::sqf::callstack::nextinstres sqf::callstack_foreach::do_next(sqf::virtualmachine* vm)
{
	// If callstack_apply is done, always return done
	if (previous_nextresult() == done)
	{
		return done;
	}
	// Receive the next "normal" result
	// and unless it is done, return it
	auto next = callstack::do_next(vm);
	if (next != done)
	{
		return next;
	}
	
	if (m_current_index >= m_array.size())
	{
		return done;
	}

	auto sptr = std::shared_ptr<callstack_foreach>(this, [](callstack_foreach*) {});
	m_codedata->loadinto(vm->stack(), sptr);
	sptr->setvar("_x", m_array[m_current_index]);
	sptr->setvar("_forEachIndex", std::make_shared<value>(m_current_index));
	m_current_index++;

	// Proceed normal
	return callstack::do_next(vm);
}