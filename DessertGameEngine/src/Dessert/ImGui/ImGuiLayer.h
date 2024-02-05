#pragma once

#include "Dessert/Layer.h"

namespace Dessert {

	class DESSERT_API ImGuiLayer: public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& event) override;

	private:
		float m_Time = 0.0f;
	};

}

