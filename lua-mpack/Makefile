# $NetBSD$

DISTNAME=	libmpack-1.0.3
PKGNAME=	${DISTNAME:S/libmpack/${LUA_PKGPREFIX}-mpack/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=tarruda/}
GITHUB_PROJECT=	libmpack

HOMEPAGE=	https://github.com/tarruda/libmpack
COMMENT=	Simple implementation of msgpack in C
LICENSE=	mit

USE_LANGUAGES=	c

LUA_VERSIONS_ACCEPTED=	51

INSTALLATION_DIRS+=	${LUA_CDIR}

.include "../../mk/bsd.prefs.mk"

do-build:
	cd ${WRKSRC}/binding/lua/ && ${CC} -O2 -fPIC -I${PREFIX}/${LUA_INCDIR} -c lmpack.c -o lmpack.o
.if ${_OPSYS_SHLIB_TYPE} == "dylib"
	cd ${WRKSRC}/binding/lua/ && ${CC} -bundle -undefined dynamic_lookup -all_load lmpack.o -o mpack.so
.else
	cd ${WRKSRC}/binding/lua/ && ${CC} -shared -fPIC lmpack.o -o mpack.so
.endif

do-install:
	${INSTALL_LIB} ${WRKSRC}/binding/lua/mpack.so ${DESTDIR}${PREFIX}/${LUA_CDIR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
