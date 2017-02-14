# $NetBSD$

DISTNAME=	arachne-pnr-e97e35c
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GITHUB:=cseed/}
GITHUB_TAG= 	e97e35c3de200083b1f420d314df166326fc48e8

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cseed/
COMMENT=	Place and route tool for FPGAs
LICENSE=	mit

USE_LANGUAGES+=		c++
USE_TOOLS+= 		gmake
LIBS+= 			-lm

#GIT_REPOSITORIES=	arachne-pnr
#GIT_REPO.arachne-pnr=	git://github.com/cseed/arachne-pnr.git
#GIT_REVISION.arachne-pnr=	52e69ed207342710080d85c7c639480e74a021d7
WRKSRC=			${WRKDIR}/arachne-pnr-${GITHUB_TAG}
MAKE_ENV+=		ICEBOX=${PREFIX}/share/icebox
MAKE_ENV+=		DESTDIR=${DESTDIR}
MAKE_ENV+= 		PREFIX=${PREFIX}

#.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
