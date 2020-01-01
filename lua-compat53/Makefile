# $NetBSD$
# $NetBSD $

DISTNAME=	lua-compat53-0.7
PKGNAME=	${DISTNAME:S/lua/${LUA_PKGPREFIX}/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=keplerproject/}
GITHUB_PROJECT=	lua-compat-5.3
GITHUB_TAG=	v${PKGVERSION_NOREV}

HOMEPAGE=	https://github.com/keplerproject/lua-compat-5.3
COMMENT=	Compatibility module providing Lua-5.3-style APIs for Lua 5.2 and 5.1
LICENSE=	mit

LUA_VERSIONS_ACCEPTED=	52 51
INSTALLATION_DIRS+=	${LUA_LDIR} ${LUA_CDIR}
INSTALLATION_DIRS+=	${LUA_LDIR}/compat53
INSTALLATION_DIRS+=	${LUA_LDIR}/compat53/c-api
INSTALLATION_DIRS+=	${LUA_CDIR}/compat53

.include "../../mk/bsd.prefs.mk"

COMMON_FLAGS_COMPILER=	-O2 -fPIC -I${PREFIX}/${LUA_INCDIR}
COMMON_FLAGS_LINKER=	-shared -fPIC

do-build:
	cd ${WRKSRC} && ${CC} ${COMMON_FLAGS_COMPILER} -c lutf8lib.c -o lutf8lib.o
	cd ${WRKSRC} && ${CC} ${COMMON_FLAGS_COMPILER} -c ltablib.c -o ltablib.o
	cd ${WRKSRC} && ${CC} ${COMMON_FLAGS_COMPILER} -c lstrlib.c -o lstrlib.o
.if ${_OPSYS_SHLIB_TYPE} == "dylib"
	cd ${WRKSRC} && ${CC} ${COMMON_FLAGS_LINKER} -undefined dynamic_lookup -install_name ${PREFIX}/${LUA_CDIR}/compat53/utf8.so lutf8lib.o -o utf8.so
	cd ${WRKSRC} && ${CC} ${COMMON_FLAGS_LINKER} -undefined dynamic_lookup -install_name ${PREFIX}/${LUA_CDIR}/compat53/table.so ltablib.o -o table.so
	cd ${WRKSRC} && ${CC} ${COMMON_FLAGS_LINKER} -undefined dynamic_lookup -install_name ${PREFIX}/${LUA_CDIR}/compat53/string.so lstrlib.o -o string.so
.else
	cd ${WRKSRC} && ${CC} ${COMMON_FLAGS_LINKER} lutf8lib.o -o utf8.so
	cd ${WRKSRC} && ${CC} ${COMMON_FLAGS_LINKER} ltablib.o -o table.so
	cd ${WRKSRC} && ${CC} ${COMMON_FLAGS_LINKER} lstrlib.o -o string.so
.endif

do-install:
	${INSTALL_LIB} ${WRKSRC}/utf8.so ${DESTDIR}${PREFIX}/${LUA_CDIR}/compat53/
	${INSTALL_LIB} ${WRKSRC}/table.so ${DESTDIR}${PREFIX}/${LUA_CDIR}/compat53/
	${INSTALL_LIB} ${WRKSRC}/string.so ${DESTDIR}${PREFIX}/${LUA_CDIR}/compat53/
	${INSTALL_DATA} ${WRKSRC}/compat53/init.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}/compat53/
	${INSTALL_DATA} ${WRKSRC}/compat53/module.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}/compat53/
	${INSTALL_DATA} ${WRKSRC}/c-api/compat-5.3.c ${DESTDIR}${PREFIX}/${LUA_LDIR}/compat53/c-api/
	${INSTALL_DATA} ${WRKSRC}/c-api/compat-5.3.h ${DESTDIR}${PREFIX}/${LUA_LDIR}/compat53/c-api/

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
