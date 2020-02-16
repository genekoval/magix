project := magix
version := 0.1.0

library = lib$(project)
test = test

install := $(library)
targets := $(install) $(test)

$(library).type = shared
define $(library).libs
 magic
endef

$(test).type = executable
define $(test).deps
 $(library)
endef
define $(test).libs
 $(project)
endef

include $(DEVROOT)/include/mkbuild/base.mk
