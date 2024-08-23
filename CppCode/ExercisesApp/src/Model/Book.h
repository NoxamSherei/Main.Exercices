#pragma once

class Book {
public:
	std::string title;
	std::string autor;
	bool isAvaliable;
	Book(std::string autor, std::string title) :title(title), autor(autor), isAvaliable(true) {}
};