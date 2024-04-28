#pragma once

#include "CWSDK/cwsdk.h"
#include "DLL.h"

namespace mod {
	class ModWidget : public cube::BaseWidget
	{
	public:
		enum HoverState
		{
			None = 0,
			Exit = 1,
			Next = 2,
			Previous = 3,
			Toggle = 4
		};
		cube::Game* game;
		int hover_state;
		int selected;
		int scroll_value;
		int max_height;
		bool changed;
		bool reached_end;
		plasma::Node* background;
		plasma::Node* button; // ToggleButton
		plasma::Node* up_button;
		plasma::Node* down_button;
		plasma::Node* scroll_button;
		std::vector<DLL*>* mods;
		void* artificial_vtable[43];

		constexpr static float desc_offset = 20.0f;

		ModWidget* ctor(cube::Game* game, plasma::Node* node, plasma::Node* background, std::vector<DLL*>* mods);

		void MouseUp(cube::MouseButton mouse_button);

		static void ModTogglePressed(uint64_t value);
		static void ScrollUp(uint64_t value);
		static void ScrollDown(uint64_t value);
		static mod::ModWidget* GetModWidget();
		int GetModHeight(DLL* dll, int text_size);
		int GetModDescriptionHeight(DLL* dll, int text_size);

		std::wstring* GetSlicedModDescription(std::wstring* str);
		int GetDescriptionLines(std::wstring* str);

		static void Draw(ModWidget* widget);
		static void Init();
		static void LoadSave(std::vector<DLL*>* mods);
		static void StoreSave(std::vector<DLL*>* mods);
	};
}