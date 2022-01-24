# $NetBSD$

GITHUB_PROJECT=	nedit-ng
GITHUB_TAG=	refs/tags/2020.1
DISTNAME=	2020.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=eteran/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/eteran/nedit-ng/
COMMENT=	Remake of nedit using Qt
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	bison
BISON_REQD=	3.0
USE_CMAKE=	yes
USE_LANGUAGES=	c++

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/c++gsl/buildlink3.mk"
.include "../../textproc/yaml-cpp/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
