#include "PhoneBook.hpp"

void	reset(void)
{
	system("clear");
	std::cout << RED << "\n📞 PhoneBook! 📞\n" << RESET;
}

int	main() {
	PhoneBook 	pb;
	std::string line;

	std::cout << RED << "\n📞 Welcome to your PhoneBook! 📞\n" << RESET;
	while (1) {
		std::cout << "\n🙋 ADD      🔎 SEARCH      🚪 EXIT\n";
		std::cin >> line;
		if (line == "ADD") {
			reset();
			pb.add();
			reset();
		}
		else if (line == "SEARCH") {
			reset();
			pb.search();
		}
		else if (line == "EXIT")
		{
			system("clear");
			break ;
		}
		else
			std::cout << "Enter a valid input!\n\n";
	}
	std::cout << "\n\n📞 Thank you! 📞\n\n";
	return (0);
}