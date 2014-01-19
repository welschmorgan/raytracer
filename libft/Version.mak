#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/28 04:55:56 by mwelsch           #+#    #+#              #
#    Updated: 2013/12/28 06:57:59 by mwelsch          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# auto increments build number
VERSION_FILE = .version
REV=$(shell date +'%k%M')

VERSION_CHANGES = .changelog
VERSION_MAJOR = 1
VERSION_MINOR = 0
VERSION_BUILD = $(shell cat $(VERSION_FILE))
VERSION_REV = $(shell echo $(REV) | tr -d ' ')

VERSION_DATE = $(shell date +'%Y%m%d')

VERSION_FLAGS = -D__VERSION_DATE=$(VERSION_DATE)
VERSION_FLAGS += -D__VERSION_BUILD=$(VERSION_BUILD)
VERSION_FLAGS += -D__VERSION_MAJOR=$(VERSION_MINOR)
VERSION_FLAGS += -D__VERSION_MINOR=$(VERSION_MAJOR)
VERSION_FLAGS += -D__VERSION_REV=$(VERSION_REV)

# build number file
$(VERSION_FILE): $(OBJS) $(OBJS_D)
	@echo "Updating version ($(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_BUILD).$(VERSION_REV))"
	@if ! test -f $(VERSION_FILE); then echo 0 > $(VERSION_FILE); fi
	@echo $$(($$(cat $(VERSION_FILE)) + 1)) > $(VERSION_FILE)
	@if ! test -f $(VERSION_CHANGES); then touch $(VERSION_CHANGES); fi
	@echo "Version $(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_BUILD).$(VERSION_REV): " | cat - $(VERSION_CHANGES) >> $(VERSION_CHANGES).tmp
	@rm -rf $(VERSION_CHANGES)
	@mv $(VERSION_CHANGES).tmp $(VERSION_CHANGES)
	@emacs $(VERSION_CHANGES)
