#!/bin/bash

hppPath="./incl/"
cppPath="./srcs/"

mkdir -p $hppPath $cppPath

for class in "$@"
do
    capClass="$(tr '[:lower:]' '[:upper:]' <<< ${class:0:1})${class:1}"
    fcapClass="$(tr '[:lower:]' '[:upper:]' <<< ${class})"
    hpp="$hppPath$capClass".hpp
    cpp="$cppPath$capClass".cpp
    # HPP
    rm -f $hpp && touch $hpp
    cat > $hpp << EOL
#ifndef ${fcapClass}_HPP
#define ${fcapClass}_HPP

class $capClass {
public:
	$capClass();
	$capClass(const $capClass & other);
	$capClass &operator=(const $capClass & other);
	~$capClass();
};

#endif

EOL

    # CPP
    rm -f $cpp && touch $cpp
    cat > $cpp << EOL
#include "$capClass.hpp"

$capClass::$capClass() {}

$capClass::$capClass(const $capClass & other) {
	*this = other;
}

$capClass & $capClass::operator=(const $capClass & other) {
	// Copy stuff
	return *this;
}

$capClass::~$capClass() {}

EOL
done

printf "\n$# classes created:\n\n"
for class in "$@"
do
    echo "$capClass.hpp/.cpp"
done


# bash ocf.sh [Class Name]