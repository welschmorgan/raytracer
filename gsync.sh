#!/bin/bash

function sync_folder()
{
	git add .
	git commit -am "Synchronizing Project"
	git push
}

sync_folder
cd libft
sync_folder
cd ../libmath
sync_folder