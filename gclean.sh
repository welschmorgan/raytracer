#!/bin/bash

function myrm
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
git remote set-url origin vogsphere@vogsphere.42.fr:infog-1-001/2013/par-1-1/rtv1/mwelsch