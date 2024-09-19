# $NetBSD$

GITHUB_PROJECT=	dlt-viewer
DISTNAME=	v2.18.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=GENIVI/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://github.com/GENIVI/dlt-viewer/
COMMENT=	GENIVI Diagnostic Log and Trace viewing program
LICENSE=	mpl-2.0

WRKSRC=		${WRKDIR}/dlt-viewer-2.18.0
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CWRAPPERS_PREPEND.cxx+=	-std=c++11

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtserialport/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
