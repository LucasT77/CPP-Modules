#include <iostream>
#include <string>
using namespace std;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

string	*low_to_high_case(char *str)
{
	string	*new_str;
	int		i;
	int		len;

	len = ft_strlen(str);
	cout << len << '\n';
	cout << str << '\n';
	new_str = new string[len];
	cout << len + 10 << '\n';
	for(i = 0; str[i]; i++)
	{
		if (str[i] >= 97 && str[i] <= 122)
			new_str[i] = str[i];
		else
			new_str[i] = str[i];
	}
	new_str[i] = '\0';
	return (new_str);
}

int main(int argc, char **argv)
{
	string	*new_str;

	if (argc < 1)
		return (0);
	if (argc == 1)
	{
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		new_str = low_to_high_case(argv[i]);
		cout << new_str;
		delete(new_str);
	}
	return (0);
}