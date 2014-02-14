#!/bin/sh

./fetch_modules.sh
for mod in libft libmath; do
	echo Removing $mod/.git
	rm -r $mod/.git
done