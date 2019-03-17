# $NetBSD$

DISTNAME=	penlight-1.6.0
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=stevedonovan/}
GITHUB_PROJECT=	Penlight
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://stevedonovan.github.io/Penlight/
COMMENT=	Set of pure Lua libraries focusing on input data handling
LICENSE=	mit

NO_BUILD=		yes
INSTALLATION_DIRS+=	${LUA_LDIR}/pl
WRKSRC=			${WRKDIR}/Penlight-${PKGVERSION_NOREV}

DEPENDS+=	${LUA_PKGPREFIX}-luafilesystem-[0-9]*:../../wip/lua-luafilesystem

do-install:
	${INSTALL_DATA} ${WRKSRC}/lua/pl/* ${DESTDIR}${PREFIX}/${LUA_LDIR}/pl

.include "../../lang/lua/module.mk"

.include "../../mk/bsd.pkg.mk"
