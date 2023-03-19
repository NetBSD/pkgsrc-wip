# $NetBSD$

DISTNAME=	lua-htmlparser-0.3.9
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/lua-//}
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=msva/}
GITHUB_PROJECT=	lua-htmlparser
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://msva.github.io/lua-htmlparser/
COMMENT=	Parse HTML text into a tree of elements with selectors
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	${LUA_LDIR}/htmlparser
WRKSRC=			${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/htmlparser.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}
	${INSTALL_DATA} ${WRKSRC}/src/htmlparser/ElementNode.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}/htmlparser
	${INSTALL_DATA} ${WRKSRC}/src/htmlparser/voidelements.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}/htmlparser

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
