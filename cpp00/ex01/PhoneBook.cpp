#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void):
	_nextIndex(0),
	_contactCount(0)
{
}

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
		std::cout << "====== Registration completed ======" << std::endl;

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
	unsigned long	fieldLength = FIELD_LENGTH > MIN_FIELD_LENGTH ? FIELD_LENGTH : MIN_FIELD_LENGTH;

	if (str.length() > fieldLength)
		return (str.substr(0, fieldLength - 1) + '.');
	return (std::string(fieldLength - str.length(), ' ') + str);
}

// how many dashes between rows
static inline std::string	dash()
{
	unsigned long	fieldLength = FIELD_LENGTH > MIN_FIELD_LENGTH ? FIELD_LENGTH : MIN_FIELD_LENGTH;

	return (std::string(fieldLength, '-'));
}

void	PhoneBook::search(void) const
{
	int				i = 0;
	int				userInputIndex;
	std::string		str = "";
	unsigned long	fieldLength = FIELD_LENGTH > MIN_FIELD_LENGTH ? FIELD_LENGTH : MIN_FIELD_LENGTH;


	// displaying table
	std::cout << "┏" << dash() << "┯" << dash() << "┯" << dash() << "┯" << dash() << "┓" << std::endl;
	std::cout << "|" << formatField("Index") <<"|" << formatField("First name") << "|" << formatField("Last name") << "|" << formatField("Nickname") <<"|" << std::endl;
	std::cout << "┣" << dash() << "╋" << dash() << "╋" << dash() << "╋" << dash() << "┫" << std::endl;
	for (i = 0; i < _contactCount; i++)
	{
		std::cout << "|" << std::string(fieldLength - 1, ' ') << i;
		std::cout << "|" << formatField(_contacts[i].getFirstName());
		std::cout << "|" << formatField(_contacts[i].getLastName());
		std::cout << "|" << formatField(_contacts[i].getNickname()) << "|" << std::endl;
	}
	std::cout << "┗" << dash() << "┷" << dash() << "┷" << dash() << "┷" << dash() << "┛" << std::endl;

	// no contact inserted, user cant choose anything from table
	if (_contactCount <= 0)
	{
		std::cout << "No contact has been inserted yet" << std::endl;
		return ;
	}

	// asking for user input for contact index
	while (str == "" && !std::cin.eof())
	{
		std::cout << "Select Index from range: " << "[0-" << _contactCount - 1 << "]: ";
		std::getline(std::cin, str);
		userInputIndex = str[0] - '0'; // todo for max_contacts >9
		if ((userInputIndex < 0 || userInputIndex > _contactCount - 1) && str != "") // this will work only for 0-9 contacts (subject OK)
			std::cout << "Invalid Index" << std::endl;
		else
			break ;
		str = "";
	}

	// displaying contact index
	if (str == "")
		return ;
	std::cout << "\nDisplaying user on Index: " << userInputIndex << std::endl;
	std::cout << _contacts[userInputIndex].getFirstName() << std::endl;
	std::cout << _contacts[userInputIndex].getLastName() << std::endl;
	std::cout << _contacts[userInputIndex].getNickname() << std::endl;
	std::cout << _contacts[userInputIndex].getPhoneNumber() << std::endl;
	std::cout << _contacts[userInputIndex].getDarkestSecret() << std::endl << std::endl;
}
