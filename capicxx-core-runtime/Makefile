# $NetBSD$

GITHUB_PROJECT=	capicxx-core-runtime
DISTNAME=	3.1.11
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=GENIVI/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://github.com/GENIVI/capicxx-core-runtime/
COMMENT=	GENIVI common API C++ core runtime
LICENSE=	mpl-2.0

WRKSRC=		${WRKDIR}/capicxx-core-runtime-3.1.11
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	CommonAPI.pc.in

.include "../../wip/dlt-daemon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
