#pragma once
#include "../Model/Book.h"
#include "../Model/LibraryType.h"

#include "vector"
#include "string"

__interface ILibraryFasade {
	void addBook(std::string autor, std::string title, LibraryType type) = 0;
	std::vector<Book> collectBooks(LibraryType type) = 0;
	std::vector<Book> collectAutorBooks(std::string autor, LibraryType type) = 0;
	std::vector<Book> collectTitleBooks(std::string title, LibraryType type) = 0;
	bool wypozycz(std::string autor, std::string title, LibraryType type) = 0;
	bool oddaj(std::string autor, std::string title, LibraryType type) = 0;
};