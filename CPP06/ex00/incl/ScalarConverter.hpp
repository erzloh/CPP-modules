#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
public:
	ScalarConverter(const ScalarConverter& other);
	~ScalarConverter();
	ScalarConverter& operator=(const ScalarConverter& other);

	static void convert(const std::string& str);

private:
	ScalarConverter();
	
	static char _char;
	static int _int;
	static float _float;
	static double _double;

	enum e_type {
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		NONE
	};

	static e_type _type;

	static bool _setChar(const std::string& str);
	static bool _setInt(const std::string& str);
	static bool _setFloat(const std::string& str);
	static bool _setDouble(const std::string& str);

	static void _castCharAndPrint();
	static void _castIntAndPrint();
	static void _castFloatAndPrint();
	static void _castDoubleAndPrint();
};

#endif
