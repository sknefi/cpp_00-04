#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define MAX_CONTACTS 8
# define MIN_FIELD_LENGTH 10 // because of the longest word from first row (First name) - dont change this
# define FIELD_LENGTH 10

class PhoneBook
{
private:
	int		_nextIndex; // index after the last contact
	int		_contactCount;
	Contact _contacts[MAX_CONTACTS];
public:
	PhoneBook();
	~PhoneBook();

	void	addContact();
	void	search() const;
};

#endif