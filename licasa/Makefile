# $NetBSD$

DISTNAME=	licasa-0.9.7
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=sanxchep/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sanxchep/licasa/
COMMENT=	Open-source image viewer and editor
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c++

REPLACE_PYTHON+=	tools/*.py

.include "../../devel/cmake/build.mk"
.include "../../lang/python/application.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
