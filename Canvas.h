#pragma once
#include "Widget.h"

namespace UI
{
	class Canvas : public Widget
	{
		set<Widget*> allWidgets;
	public:
		/*template <typename Type = Widget, IS_BASE_OF(Widget, Type)>
		FORCEINLINE void AddWidget(Type* _widget)
		{
			AddChild(_widget, AT_KEEP_RELATIVE);
		}
		template <typename Type = Widget, IS_BASE_OF(Widget, Type)>
		FORCEINLINE void RemoveWidget(Type* _widget)
		{
			RemoveChild(_widget);
		}*/

		FORCEINLINE void AddWidget(Widget* _widget)
		{
			allWidgets.insert(_widget);
		}
		FORCEINLINE void RemoveWidget(Widget* _widget)
		{
			allWidgets.erase(_widget);
		}
		FORCEINLINE void RemoveWidgets()
		{
			using Iterator = set<Widget*>::iterator;
				
			for (Iterator _it = allWidgets.begin(); _it != allWidgets.end(); )
			{
				Widget* _widget = *_it;
				++_it;
				allWidgets.erase(_widget);
				_widget->Deconstruct();
			}
		}
		FORCEINLINE virtual Vector2f GetSize() const override
		{
			// TODO ?
			return Vector2f();
		}
	public:
		Canvas(const string& _name, const RenderType& _type = Screen);
		Canvas(const Canvas& _other);

	public:
		virtual void Render(RenderWindow& _window) override;
		void UpdateWidgets();
		virtual void Construct() override;
		virtual void BeginDestroy() override;
		//virtual void Destroy() override;
		
	};
}


