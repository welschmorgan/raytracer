#!/bin/sh

./fetch_modules.sh
for mod in libft libmath; do
	echo Removing $mod/.git
	rm -ir $mod/.git
done
rm -ri .gitmodules
rm -ri *.sh