# $NetBSD$

GITHUB_PROJECT=	simgrid
DISTNAME=	v3_13
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=simgrid/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://simgrid.org/
COMMENT=	Simulator of distributed applications
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/simgrid-3_13
USE_CMAKE=	yes
USE_LANGUAGES=	c c++ fortran
USE_TOOLS+=	perl

BUILD_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen

.include "../../devel/libf2c/buildlink3.mk"
.include "../../graphics/graphviz/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
