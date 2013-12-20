Description := Static runtime libraries for clang/NetBSD.

###

#CC := clang
Arch := unknown
Configs := full

###

FUNCTIONS.full := $(CommonFunctions) $(ArchFunctions)
CFLAGS := -Wall -O3 -fomit-frame-pointer

CFLAGS.full := $(CFLAGS)

# Always use optimized variants.
OPTIMIZED := 1

# We don't need to use visibility hidden on Linux.
VISIBILITY_HIDDEN := 0

SHARED_LIBRARY_SUFFIX := so
