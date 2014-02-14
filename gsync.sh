#!/bin/bash

function sync_folder()
{
	make fclean
	git add .
	git commit -am "Synchronizing Project"
	git push
}

cd libft
sync_folder
cd ../libmath
sync_folder
cd ..
sync_folder