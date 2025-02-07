#pragma once
#include "Actor.h"
#include "Widget.h"

namespace UI
{
	class HUD : public Actor
	{
		set<Widget*> allWidgets;
		Widget* currentWidget;

		FORCEINLINE void RegisterWidget(Widget* _widget)
		{
			if (allWidgets.contains(_widget)) return;
			allWidgets.insert(_widget);
		}
	public:
		template <typename Type, typename ...Args, IS_BASE_OF(Widget, Type)>
		FORCEINLINE Type* SpawnWidget(Args&&... _args)
		{
			Type* _widget = level->SpawnActor<Type>(forward<Args>(_args)...));
			RegisterWidget(_widget);
			return _widget;
		}
		FORCEINLINE void UnregisterWidget(Widget* _widget)
		{
			if (!allWidgets.contains(_widget)) return;
			allWidgets.erase(_widget);
		}

	public:
		HUD();
		HUD(const HUD& _other);

	public:
		void AddToViewport(Widget* _widget);
		void RemoveFromViewport(Widget* _widget);
	};
}