#!/bin/bash

function sync_folder()
{
	make fclean
	git add .
	git commit -am "Synchronizing Project"
	git push origin master
}

cd libft
sync_folder
cd ../libmath
sync_folder
cd ..
sync_folder