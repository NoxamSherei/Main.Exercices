#pragma once

#include "../Model/Book.h"

#include "vector"
#include "string"

class ILibrary {
public:
	virtual void addBook(std::string, std::string) = 0;
	virtual std::vector<Book> collectBooks() = 0;
	virtual std::vector<Book> collectAutorBooks(std::string) = 0;
	virtual std::vector<Book> collectTitleBooks(std::string) = 0;
	virtual bool AutorExist(std::string) = 0;
	virtual bool TitleExist(std::string) = 0;
	virtual bool BookExist(std::string, std::string) = 0;
	virtual bool BookIsAvaliable(std::string autor, std::string title) = 0;
	virtual bool wypozycz(std::string, std::string) = 0;
	virtual bool oddaj(std::string, std::string) = 0;
};