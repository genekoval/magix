project := magix
version := 0.1.0

STD := c++20

library = lib$(project)

install := $(library)
targets := $(install)

$(library).type = shared
define $(library).libs
 magic
endef

include mkbuild/base.mk
