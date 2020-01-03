# $NetBSD$

DISTNAME=	lua-say-1.3
PKGNAME=	${DISTNAME:S/lua/${LUA_PKGPREFIX}/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Olivine-Labs/}
GITHUB_PROJECT=	say
GITHUB_TAG=	v${PKGVERSION_NOREV}-1

HOMEPAGE=	https://github.com/Olivine-Labs/say
COMMENT=	Lua string hashing library, useful for internationalization
LICENSE=	mit

NO_BUILD=	yes

INSTALLATION_DIRS+=	${LUA_LDIR} ${LUA_LDIR}/say

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/init.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}/say/


.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
