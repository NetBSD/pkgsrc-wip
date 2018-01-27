# $NetBSD: Makefile,v 1.34 2017/08/24 20:03:00 adam Exp $

PKGNAME=	cgal-4.11
DISTNAME=	CGAL-4.11
CATEGORIES=	wip
MASTER_SITES=	https://github.com/CGAL/cgal/releases/download/releases%2FCGAL-4.11/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	reinoud@NetBSD.org
HOMEPAGE=	http://www.cgal.org/
COMMENT=	Computational Geometry Algorithms Library
LICENSE=	gnu-lgpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

REPLACE_BASH+=	scripts/cgal_create_CMakeLists
REPLACE_BASH+=	scripts/cgal_create_cmake_script

pre-install:
	find ${WRKSRC} -name \*.orig -exec rm {} \;

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
