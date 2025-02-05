#pragma once
#include "Image.h"
#include "Widget.h"

namespace UI
{
	struct ButtonData
	{
		function<void()> hoveredCallback;
		function<void()> unHoveredCallback;
		function<void()> pressedCallback;
		function<void()> releasedCallback;
		function<void()> heldCallback;

		ButtonData() = default;

		ButtonData(const function<void()>& _hoveredCallback,
			const function<void()>& _unHoveredCallback,
			const function<void()>& _pressedCallback,
			const function<void()>& _releasedCallback,
			const function<void()>& _heldCallback)
		{
			hoveredCallback = _hoveredCallback;
			unHoveredCallback = _unHoveredCallback;
			pressedCallback = _pressedCallback;
			releasedCallback = _releasedCallback;
			heldCallback = _heldCallback;
		};

	};

	class Button : public Widget
	{
		bool isSelected;
		bool isHeld;
		bool isHovered;
		UI::Image* foreground;
		ButtonData data;

	public:
		FORCEINLINE virtual void SetPosition(const Vector2f& _position) override
		{
			Super::SetPosition(_position);
			foreground->SetPosition(_position);
		}
		FORCEINLINE bool IsSelected() const
		{
			return isSelected;
		}
		FORCEINLINE bool IsHovered() const
		{
			return isHovered;
		}
		FORCEINLINE void SetForeground(Image* _foreground)
		{
			foreground = _foreground;
		}
		FORCEINLINE Widget* GetForeground() const
		{
			return foreground;
		}
		FORCEINLINE ButtonData& GetData()
		{
			return data;
		}

	public:

		Button(UI::Image* _image, const ButtonData& _data = ButtonData(), const string& _name = "Button", const RenderType& _type = Screen);
		Button(const Button& _other);
	public:
		bool OnPressed();
		void OnHeld();
		void OnReleased();
		void OnHovered();
		void OnUnhovered();

		void Execute(const Event& _event);
		virtual void Construct() override;
		virtual void Deconstruct() override;
		virtual void Render(RenderWindow& _window) override;

	};
}

