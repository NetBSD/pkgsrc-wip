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

SOLVER_DISTFILE=	solvers-64919f75f.tgz
DISTFILES=		${DEFAULT_DISTFILES} ${SOLVER_DISTFILE}

SITES.${SOLVER_DISTFILE}=	https://coin-or-tools.github.io/ThirdParty-ASL/

post-extract:
	cd ${WRKSRC} && ${LN} -s ../solvers


.include "../../mk/bsd.pkg.mk"
