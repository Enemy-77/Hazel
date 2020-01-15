#pragma once

#include "Event.h"


namespace Hazel {

	class HAZEL_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		KeyEvent(int keycode)
			: m_KeyCode(keycode) {}

		int m_KeyCode;

	};


	class HAZEL_API KeyPressEvent : public KeyEvent
	{
	public:
		KeyPressEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeateCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeateCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KetPressedEvent" << m_KeyCode << "(" << m_RepeateCount << "repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int m_RepeateCount;
	};

	class HAZEL_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent" << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};


}
