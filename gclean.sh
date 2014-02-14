#!/bin/sh

function myrm()
{
	echo Removing $@
	rm -rf $@
}

./gmods.sh
for mod in libft libmath; do
	myrm $mod/.git
done
myrm .gitmodules
myrm *.sh