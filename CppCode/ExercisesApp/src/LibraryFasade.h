#pragma once
#include "ILibrary.h"
#include "LibraryA.h"
#include "LibraryB.h"
#include "LibraryType.h"
#include "vector"
#include "utility"
class LibraryFasade {
private:
	using LibraryPtr = std::shared_ptr<ILibrary>;
	std::unordered_map<int, LibraryPtr> libraries;
	LibraryPtr& getLibrary(LibraryType type) {
		return libraries[as_integer(type)];
	}
public:
	LibraryFasade(std::unordered_map<int, LibraryPtr> libraries) :libraries(libraries) {}
	void addBook(std::string autor, std::string title, LibraryType type) {
		LibraryPtr& library = getLibrary(type);
		library->addBook(autor, title);
	}
	std::vector<Book> collectBooks(LibraryType type) {
		LibraryPtr& library = getLibrary(type);
		return library->collectBooks();
	}
	std::vector<Book> collectAutorBooks(std::string autor, LibraryType type) {
		LibraryPtr& library = getLibrary(type);
		return library->collectAutorBooks(autor);
	}
	std::vector<Book> collectTitleBooks(std::string title, LibraryType type) {
		LibraryPtr& library = getLibrary(type);
		return library->collectTitleBooks(title);
	}
	bool wypozycz(std::string autor, std::string title, LibraryType type) {
		LibraryPtr& library = getLibrary(type);
		return library->wypozycz(autor, title);
	}
	bool oddaj(std::string autor, std::string title, LibraryType type) {
		LibraryPtr& library = getLibrary(type);
		return library->oddaj(autor, title);
	};
};


class LibraryFasadeBuilder {
private:
	using LibraryPtr = std::shared_ptr<ILibrary>;
	std::vector<std::pair<int, LibraryPtr>> librariesToAdd;
public:
	LibraryFasadeBuilder() = default;
	LibraryFasadeBuilder* AddLibrary(LibraryType type, LibraryPtr library) {
		librariesToAdd.push_back(std::make_pair(as_integer(type), std::move(library)));
		return this;
	}

	LibraryFasade* Build() {
		std::unordered_map<int, LibraryPtr> libraries;
		for (auto library : librariesToAdd) {
			libraries[library.first] = library.second;
		}
		return new LibraryFasade(libraries);
	}
};