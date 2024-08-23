#pragma once
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "src/LibraryFasade.h"
#include "src/Model/LibraryType.h"
#include "src/Model/Book.h"

std::unique_ptr<ILibraryFasade> Build(std::unique_ptr<LibraryFasadeBuilder>&& builder) {
	std::unique_ptr<ILibraryFasade> library = builder->
		AddLibrary(LibraryType::LibA, std::make_shared<LibraryA>())->
		AddLibrary(LibraryType::LibB, std::make_shared<LibraryB>())->
		Build();
	return library;
}

int main()
{
	auto libraryFasedeBuilder = std::make_unique<LibraryFasadeBuilder>();
	std::unique_ptr<ILibraryFasade> library = Build(std::move(libraryFasedeBuilder));
	library->addBook("Frank", "Dune1", LibraryType::LibA);
	library->addBook("Smith", "Pamietniki wampirow", LibraryType::LibA);
	library->addBook("Trudi Caravan", "Ambasador", LibraryType::LibA);
	library->addBook("Smith", "Pamietniki wampirow", LibraryType::LibB);
	library->addBook("Trudi Caravan", "Ambasador", LibraryType::LibB);
	library->addBook("Trudi Caravan", "Gilidia Magów", LibraryType::LibA);
	std::cout << "LibA-----------" << std::endl;
	for (const auto& elem : library->collectBooks(LibraryType::LibA)) {
		std::cout << elem.autor << " " << elem.title << " " << elem.isAvaliable << std::endl;
	}
	std::cout << "LibB-----------" << std::endl;
	for (const auto& elem : library->collectBooks(LibraryType::LibB)) {
		std::cout << elem.autor << " " << elem.title << " " << elem.isAvaliable << std::endl;
	}
	std::cout << "-----------" << std::endl;
	for (const auto& elem : library->collectAutorBooks("Trudi Caravan", LibraryType::LibA)) {
		std::cout << elem.autor << " " << elem.title << " " << elem.isAvaliable << std::endl;
	}
	std::cout << "-----------" << std::endl;
	{
		std::vector<Book> elem = library->collectTitleBooks("Gilidia Magów", LibraryType::LibA);
		if (elem.empty()) {
			std::cout << "book is missing";
		}
		else {
			for (const auto& elem : library->collectAutorBooks("Trudi Caravan", LibraryType::LibA)) {
				std::cout << elem.autor << " " << elem.title << " " << elem.isAvaliable << std::endl;
			}
		}
	}
	std::cout << "-----------" << std::endl;
	library->wypozycz("Trudi Caravan", "Gilidia Magów", LibraryType::LibA);

	for (const auto& elem : library->collectAutorBooks("Trudi Caravan", LibraryType::LibA)) {
		std::cout << elem.autor << " " << elem.title << " " << elem.isAvaliable << std::endl;
	}
	std::cout << "-----------" << std::endl;
	library->oddaj("Trudi Caravan", "Gilidia Magów", LibraryType::LibA);

	for (const auto& elem : library->collectAutorBooks("Trudi Caravan", LibraryType::LibA)) {
		std::cout << elem.autor << " " << elem.title << " " << elem.isAvaliable << std::endl;
	}
}