# $NetBSD: Makefile,v 1.34 2017/08/24 20:03:00 adam Exp $

DISTNAME=	CGAL-4.14
PKGNAME=	cgal-4.14
CATEGORIES=	wip
MASTER_SITES=	https://github.com/CGAL/cgal/releases/download/releases%2FCGAL-4.14/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	reinoud@NetBSD.org
HOMEPAGE=	http://www.cgal.org/
COMMENT=	Computational Geometry Algorithms Library
LICENSE=	gnu-lgpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++03

REPLACE_BASH+=	scripts/cgal_create_CMakeLists
REPLACE_BASH+=	scripts/cgal_create_cmake_script

pre-install:
	find ${WRKSRC} -name \*.orig -exec rm {} \;

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
