# $NetBSD$

GITHUB_PROJECT=	abc
GITHUB_TAG=	ef5389d31526003c2ebd7e6d6d6fe3848a20f0a2
DISTNAME=	ef5389d31526003c2ebd7e6d6d6fe3848a20f0a2
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=The-OpenRoad-Project/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/The-OpenRoad-Project/abc/
COMMENT=	System for Sequential Logic Synthesis and Formal Verification
#LICENSE=	https://github.com/The-OpenROAD-Project/abc?tab=License-1-ov-file

WRKSRC=		${WRKDIR}/abc-ef5389d31526003c2ebd7e6d6d6fe3848a20f0a2
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	bin

do-install:
	cd ${WRKSRC}/cmake-pkgsrc-build && ${GMAKE} all && ${INSTALL} abc ${DESTDIR}${PREFIX}/bin

.include "../../mk/readline.buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
