# $NetBSD$

DISTNAME=	licasa-0.8.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=sanxchep/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sanxchep/licasa/
COMMENT=	Open-source image viewer and editor
LICENSE=	2-clause-bsd

#WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c++

.include "../../devel/cmake/build.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
