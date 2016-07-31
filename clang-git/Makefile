# $NetBSD$

PKGNAME=	clang-4.0.0
PYTHON_FOR_BUILD_ONLY=	yes

CMAKE_ARGS+=	-DCLANG_ENABLE_STATIC_ANALYZER=OFF

# There are some contrib utilities written in python here.
# We don't want to add a python runtime dependency for that.
CHECK_INTERPRETER_SKIP+=	share/clang/*

.PHONY: install-clang-cpp
post-install: install-clang-cpp
install-clang-cpp:
	${LN} -s clang ${DESTDIR}${PREFIX}/bin/clang-cpp

.include "../../wip/clang-git/Makefile.common"
