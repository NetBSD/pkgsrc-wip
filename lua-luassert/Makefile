# $NetBSD$

DISTNAME=	lua-luassert-1.7.11
PKGNAME=	${DISTNAME:S/lua/${LUA_PKGPREFIX}/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Olivine-Labs/}
GITHUB_PROJECT=	luassert
GITHUB_TAG=	v${PKGVERSION_NOREV}

HOMEPAGE=	https://github.com/Olivine-Labs/luassert
COMMENT=	Lua Assertions Extension library
LICENSE=	mit

NO_BUILD=	yes

INSTALLATION_DIRS+=	${LUA_LDIR}
INSTALLATION_DIRS+=	${LUA_LDIR}/luassert
INSTALLATION_DIRS+=	${LUA_LDIR}/luassert/matchers
INSTALLATION_DIRS+=	${LUA_LDIR}/luassert/formatters
INSTALLATION_DIRS+=	${LUA_LDIR}/luassert/languages

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/*.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}/luassert/
	${INSTALL_DATA} ${WRKSRC}/src/matchers/*.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}/luassert/matchers/
	${INSTALL_DATA} ${WRKSRC}/src/formatters/*.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}/luassert/formatters/
	${INSTALL_DATA} ${WRKSRC}/src/languages/*.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}/luassert/languages/

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
