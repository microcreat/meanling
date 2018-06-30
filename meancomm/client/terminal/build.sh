#!/bin/sh
pro_path=$(pwd)

cJSON_version=1.7.7

echo -e "\033[32m*************************************************************\033[0m"
echo -e "\033[32mBuild the Meanling.....\033[0m"
echo -e "\033[32mPlease check the build compiler options\033[0m"
echo -e "\033[32m*************************************************************\033[0m"
echo -e "\033[31ma  platform is x86 \033[0m"
echo -e "\033[31mb  platform is arm\033[0m"
echo -e "\033[31mc  platform is board\033[0m"
echo -e "\033[31m********************\033[0m"
read option

case $option in
	a) platform=x86;;
	b) platform=arm;;
	c) platform=board;; 
    *) echo "not correct build option input"; return;;       
esac 
echo -e "\033[33mplatform is $platform \033[0m";

if [ "$platform" = x86 ]; then
crosstools_version=$(gcc -v)
crosstools=
make -C platform/$platform PRO_PATH=$pro_path  CROSS_COMPILE=$crosstools 
elif [ "$platform" != arm ]; then
crosstools=
elif [ "$platform" != board ]; then
crosstools=
fi

echo -e "\033[32m******************* build is finish! ************************\033[0m"
echo -e "\033[32m*************************************************************\033[0m"
