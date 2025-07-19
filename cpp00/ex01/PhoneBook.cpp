#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) { }

PhoneBook::~PhoneBook(void) { }

void	PhoneBook::addContact(void)
{
	Contact		tempContact;
	std::string	firstName = "";
	std::string lastName = "";
	std::string	nickName = "";
	std::string phoneNumber = "";
	std::string	darkestSecret = "";

	while (firstName == "" && !std::cin.eof())
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, firstName);
		tempContact.setFirstName(firstName);
	}

	while (lastName == "" && !std::cin.eof())
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, lastName);
		tempContact.setLastName(lastName);
	}

	while (nickName == "" && !std::cin.eof())
	{
		std::cout << "Enter nickname: ";
		std::getline(std::cin, nickName);
		tempContact.setNickname(nickName);	
	}

	while (phoneNumber == "" && !std::cin.eof())
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, phoneNumber);
		tempContact.setPhoneNumber(phoneNumber);
	}

	while (darkestSecret == "" && !std::cin.eof())
	{
		std::cout << "Enter your darkest secret: ";
		std::getline(std::cin, darkestSecret);
		tempContact.setDarkestSecret(darkestSecret);
	}
	
	if (!std::cin.eof())
		std::cout << "=== Registration completed ===\n" << std::endl;

	if (_nextIndex >= MAX_CONTACTS)
	{
		_nextIndex = 0;
		_contactCount = MAX_CONTACTS;
	}
	if (_contactCount < MAX_CONTACTS)
		_contactCount++;
	_contacts[_nextIndex] = tempContact;
	_nextIndex++;
}

static std::string	formatField(std::string str)
{
	if (str.length() > MAX_FIELD_LENGTH)
		return (str.substr(0, MAX_FIELD_LENGTH - 1) + '.');
	return (std::string(MAX_FIELD_LENGTH - str.length(), ' ') + str);
}

void	PhoneBook::search(void) const
{
	int		i = 0;

	std::cout << "┏----------┯----------┯----------┯----------┓" << std::endl;
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	std::cout << "┣----------╋----------╋----------╋----------┫" << std::endl;
	for (i = 0; i < _contactCount; i++)
	{
		std::cout << "|" << std::string(MAX_FIELD_LENGTH - 1, ' ') << i;
		std::cout << "|" << formatField(_contacts[i].getFirstName());
		std::cout << "|" << formatField(_contacts[i].getLastName());
		std::cout << "|" << formatField(_contacts[i].getNickname()) << "|" << std::endl;
	}
	std::cout << "┗----------┷----------┷----------┷----------┛" << std::endl;

	std::cin << "Select Index from range: " << "0-" << i << std::endl;
	
}