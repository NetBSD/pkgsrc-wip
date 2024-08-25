# $NetBSD$

DISTNAME=	2.0.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=coin-or-tools/}
GITHUB_PROJECT=	ThirdParty-ASL
GITHUB_TAG=	refs/tags/releases/2.0.1
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/coin-or-tools/ThirdParty-ASL/
COMMENT=	COIN-OR autotools harness to build AMPL Solver Library
LICENSE=	epl-v1.0

WRKSRC=		${WRKDIR}/ThirdParty-ASL-releases-2.0.1
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	wget tar
USE_LANGUAGES=	c

PKGCONFIG_OVERRIDE+=	coinasl.pc.in

SOLVER_MASTER_SITE=	https://coin-or-tools.github.io/ThirdParty-ASL
SOLVER_DISTFILE=	solvers-64919f75f.tgz

# TODO: The SOLVER_DISTFILE needs to be in distinfo, extracted automatically
# FreeBSD port math/asl creates a soft link to auto-extracted file. How to do that in pkgsrc?
# Change USE_TOOLS accordingly
post-extract:
	cd ${WRKSRC} && wget --no-check-certificate ${SOLVER_MASTER_SITE}/${SOLVER_DISTFILE} && tar xvzf ${SOLVER_DISTFILE}


.include "../../mk/bsd.pkg.mk"
