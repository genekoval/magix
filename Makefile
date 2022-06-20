project := magix

STD := c++20

library := lib$(project)

install := $(library)
targets := $(install)

$(library).type := shared
$(library).libs := magic

install.directories = $(include)/$(project)

files = $(include) $(src) Makefile VERSION

include mkbuild/base.mk
