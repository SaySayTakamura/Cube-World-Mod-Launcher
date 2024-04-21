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
		int page;
		bool changed;
		plasma::Node* background;
		std::vector<DLL*>* mods;
		void* artificial_vtable[43];

		plasma::Node* test_node_1;
		plasma::Node* test_node_2;
		plasma::Node* test_node_3;
		plasma::Node* test_node_4;
		plasma::Node* test_node_5;
		plasma::Node* test_node_6;

		ModWidget* ctor(cube::Game* game, plasma::Node* node, plasma::Node* background, std::vector<DLL*>* mods);

		void MouseUp(cube::MouseButton mouse_button);
		bool NextPageAvailable();
		bool PreviousPageAvailable();

		static void test(uint64_t value);

		static void Draw(ModWidget* widget);
		static void Init();
		static void LoadSave(std::vector<DLL*>* mods);
		static void StoreSave(std::vector<DLL*>* mods);
	};
}