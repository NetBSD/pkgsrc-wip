# $NetBSD$

DISTNAME=	arachne-pnr-52e69ed
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GITHUB:=cliffordwolf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cliffordwolf/
COMMENT=	Place and route tool for FPGAs
LICENSE=	mit

USE_LANGUAGES+=		c++
USE_TOOLS+= 		gmake
LIBS+= 			-lm

GIT_REPOSITORIES=	arachne-pnr
GIT_REPO.arachne-pnr=	git://github.com/cseed/arachne-pnr.git
GIT_REVISION.arachne-pnr=	52e69ed207342710080d85c7c639480e74a021d7
WRKSRC=			${WRKDIR}/arachne-pnr
MAKE_ENV+=		ICEBOX=${PREFIX}/share/icebox
MAKE_ENV+=		DESTDIR=${DESTDIR}
MAKE_ENV+= 		PREFIX=${PREFIX}

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
