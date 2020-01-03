# $NetBSD$

DISTNAME=	lua-mediator-1.1.2
PKGNAME=	${DISTNAME:S/lua/${LUA_PKGPREFIX}/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Olivine-Labs/}
GITHUB_PROJECT=	mediator_lua
GITHUB_TAG=	v${PKGVERSION_NOREV}-0

HOMEPAGE=	https://github.com/Olivine-Labs/mediator_lua
COMMENT=	Mediator pattern implementation for pub-sub management
LICENSE=	mit

NO_BUILD=	yes

INSTALLATION_DIRS+=	${LUA_LDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/mediator.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}/


.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
