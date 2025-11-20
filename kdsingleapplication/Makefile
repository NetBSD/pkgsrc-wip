# $NetBSD$

DISTNAME=	kdsingleapplication-1.2.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=KDAB/}
GITHUB_PROJECT=	KDSingleApplication
GITHUB_RELEASE=	v1.2.0
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KDAB/KDSingleApplication/
COMMENT=	KDAB's helper class for single-instance policy applications
LICENSE=	mit

WRKSRC=			${WRKDIR}/KDSingleApplication-1.2.0
USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c++

.include "../../devel/cmake/build.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
