#pragma once

#include "Dessert/Core.h"
#include "Dessert/Events/Event.h"


namespace Dessert {

	class DESSERT_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		//A layer only have a name in debug
		std::string m_DebugName;
	};
}

