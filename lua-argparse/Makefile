# $NetBSD$

DISTNAME=	lua-argparse-0.6.0
PKGNAME=	${DISTNAME:S/lua/${LUA_PKGPREFIX}/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mpeterv/}
GITHUB_PROJECT=	argparse

HOMEPAGE=	https://github.com/mpeterv/argparse
COMMENT=	Feature-rich command-line argument parser
LICENSE=	mit

NO_BUILD=	yes
NO_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:S/lua-//}

INSTALLATION_DIRS+=	${LUA_LDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/*.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}/

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
