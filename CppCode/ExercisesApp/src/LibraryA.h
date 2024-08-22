#pragma once
#include "ILibrary.h"
#include "unordered_map"

class LibraryA : public ILibrary {
private:
	using BookPtr = std::shared_ptr<Book>;
	using MapBooks = std::unordered_map<std::string, BookPtr>;
	std::unordered_map<std::string, BookPtr> Books;
	std::unordered_map<std::string, MapBooks> BooksByTitle;
	std::unordered_map<std::string, MapBooks> BooksByAutors;
private:
	std::string GetBookKey(std::string autor, std::string title) {
		return autor + title;
	}
public:
	void addBook(std::string autor, std::string title) {
		BookPtr b = std::make_shared<Book>(autor, title);
		Books[GetBookKey(b->autor, b->title)] = b;
		BooksByTitle[title][autor] = b;
		BooksByAutors[autor][title] = b;
	}
	std::vector<Book> collectBooks() {
		std::vector<Book> result;
		for (const auto& book : Books) {
			result.push_back(*book.second);
		}
		return result;
	}
	std::vector<Book> collectAutorBooks(std::string autor) {
		std::vector<Book> result;
		if (!AutorExist(autor)) {
			return result;
		}
		for (const auto& book : BooksByAutors[autor]) {
			result.push_back(*book.second);
		}
		return result;
	}
	std::vector<Book> collectTitleBooks(std::string title) {
		std::vector<Book> result;
		if (!TitleExist(title)) {
			return result;
		}
		for (const auto& book : BooksByTitle[title]) {
			result.push_back(*book.second);
		}
		return result;
	}
	bool AutorExist(std::string autor) {
		return BooksByAutors.contains(autor);
	}
	bool TitleExist(std::string title) {
		return BooksByTitle.contains(title);
	}
	bool BookExist(std::string autor, std::string title) {
		return Books.contains(GetBookKey(autor, title));
	}
	bool BookIsAvaliable(std::string autor, std::string title) {
		return Books[GetBookKey(autor, title)]->isAvaliable;
	}
	bool wypozycz(std::string autor, std::string title) {
		if (!BookExist(autor, title)) {
			return false;
		}
		auto book = Books[GetBookKey(autor, title)];
		if (!BookIsAvaliable(autor, title)) {
			return false;
		}
		book->isAvaliable = false;
		return true;
	}
	bool oddaj(std::string autor, std::string title) {
		if (!BookExist(autor, title)) {
			return false;
		}
		auto book = Books[GetBookKey(autor, title)];
		if (BookIsAvaliable(autor, title)) {
			return false;
		}
		book->isAvaliable = true;
		return true;
	}
};