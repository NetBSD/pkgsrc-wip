# $NetBSD$

PKGNAME=	mari0-1.6
DISTNAME=	mari0-source
CATEGORIES=	wip
MASTER_SITES=	http://stabyourself.net/dl.php?file=mari0-1006/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://stabyourself.net/mari0
COMMENT=	Recreation of Super Mario Bros
LICENSE=	mit # https://github.com/Stabyourself/mari0/blob/master/README.md

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

LOVE_GAME=	mari0
LOVE_DATA=	${PKGNAME:S/-/_/}.love
LOVE_VERSION=	0.8

.include "../../wip/mk/love.mk"
.include "../../mk/bsd.pkg.mk"
