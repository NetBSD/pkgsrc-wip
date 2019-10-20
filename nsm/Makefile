# $NetBSD$

GITHUB_PROJECT=	nsm
DISTNAME=	nsm-1.15
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=nifty-site-manager/}
GITHUB_TAG=	v1.15

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://www.nift.cc/
COMMENT=	Cross-platform git- and LaTeX-like command-line website manager
LICENSE=	mit

USE_LANGUAGES=		c++
INSTALLATION_DIRS=	bin
BUILD_TARGET=		nsm

# https://github.com/nifty-site-manager/nsm/pull/1
SUBST_CLASSES+=		cc
SUBST_STAGE.cc=		pre-build
SUBST_MESSAGE.cc=	fixing cc
SUBST_FILES.cc=		Makefile
SUBST_SED.cc+=		-e 's,g++,${CXX:Q},g'

# We have lots of system specific assumptions and no
# real portable install target in the Makefile
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nift ${DESTDIR}${PREFIX}/bin/nift
	${INSTALL_PROGRAM} ${WRKSRC}/nsm ${DESTDIR}${PREFIX}/bin/nsm

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
