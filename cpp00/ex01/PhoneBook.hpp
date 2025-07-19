#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define MAX_CONTACTS 8
# define MAX_FIELD_LENGTH 10

class PhoneBook
{
private:
	int		_nextIndex; // index after the last contact
	int		_contactCount;
	Contact _contacts[MAX_CONTACTS];
public:
	PhoneBook(void);
	~PhoneBook(void);
	void	addContact(void);
	void	search(void) const;
};

#endif