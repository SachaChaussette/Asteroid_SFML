#pragma once
#include "Widget.h"

namespace UI
{
	class Canvas : public Widget
	{
		set<Widget*> allWidgets;
	public:
		template <typename Type = Widget, IS_BASE_OF(Widget, Type)>
		FORCEINLINE void AddWidget(Type* _widget)
		{
			AddChild(_widget, AT_KEEP_RELATIVE);
			allWidgets.insert(_widget);
		}
		template <typename Type = Widget, IS_BASE_OF(Widget, Type)>
		FORCEINLINE void RemoveWidget(Type* _widget)
		{
			if (!allWidgets.contains(_widget)) return;
			RemoveChild(_widget);
			allWidgets.erase(_widget);
		}

	public:
		Canvas(const string& _name, const RenderType& _type = Screen);

	public:
		virtual void Render(RenderWindow& _window) override;
	};
}


