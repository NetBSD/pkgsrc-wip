# $NetBSD: Makefile,v 1.1.1.1 2009/11/05 11:53:58 ondratu Exp $
#

DISTNAME=	PythonMagick-0.9.1
PKGNAME=        ${PYPKGPREFIX}-PythonMagick-0.9.1

CATEGORIES=	python graphics
MASTER_SITES=	http://www.imagemagick.org/download/python/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER= 	pkgsrc@blackmouse.biz
HOMEPAGE=	http://www.imagemagick.org/
COMMENT=	Python binding for ImageMagick

USE_LANGUAGES=	c c++
USE_TOOLS+=     pkg-config

PKG_DESTDIR_SUPPORT=    user-destdir
GNU_CONFIGURE=  yes

#PYDISTUTILSPKG= yes
#PY_PATCHPLIST=  yes

PLIST_SUBST+=	PYINC=${PYINC} PYSITELIB=${PYSITELIB}

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../devel/boost-python/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
