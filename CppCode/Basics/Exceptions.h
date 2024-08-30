#pragma once
#include "string"

namespace Exceptions {
	class MyException : public std::exception {
	public:
		std::string message = "";

		MyException(std::string ex, std::string message) :
			std::exception(ex.c_str()),
			message(message) {

		}
	};

	class Book {
		std::string name = "";
		std::string description = "";
		std::string autor = "";
	public:
		Book() = default;
		bool Validate() {
			if (name.length() <= 0) {
				return false;
			}
			if (description.length() <= 0) {
				return false;
			}
			if (autor.length() <= 0) {
				return false;
			}
			return true;
		}
		void SetName(std::string name) {
			if (name.length() == 0) {
				throw std::exception();
			}
			this->name = name;
		}
		void SetDesc(std::string desc) {
			if (desc.length() == 0) {
				throw std::exception("xxzzyy");
			}
			this->description = desc;
		}
		void SetAutor(std::string autor) {
			if (autor.length() == 0) {
				throw MyException("xxzzyy", "aabbcc");
			}
			this->autor = autor;
		}
	};

	void doExample() {
		Book book;
		try {
			book.SetAutor("");
			book.SetDesc("");
			book.SetName("");
		}
		catch (MyException ex) {
			std::cout << ex.what() << " " << ex.message;
		}
		catch (std::exception ex) {
			std::cout << ex.what();
		}
		if (!book.Validate()) {
			std::cout << "error";
		}
		else
		{
			std::cout << "ok";
		}
	}
}