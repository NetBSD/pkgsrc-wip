# $NetBSD$

PKGNAME=		clang-6.0.0
PYTHON_FOR_BUILD_ONLY=	yes

CMAKE_ARGS+=	-DCLANG_ENABLE_STATIC_ANALYZER=OFF

# There are some contrib utilities written in python here.
# We don't want to add a python runtime dependency for that.
CHECK_INTERPRETER_SKIP+=	share/clang/*

.include "../../wip/clang-netbsd/Makefile.common"
