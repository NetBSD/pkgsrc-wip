# $NetBSD: Makefile,v 1.1 2014/02/18 21:06:49 jihbed Exp $

DISTNAME=	imread-0.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	https://pypi.python.org/packages/source/i/imread/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://luispedro.org/software/imread
COMMENT=	Imread: Image reading library
LICENSE=	mit

USE_LANGUAGES=	c c++

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
