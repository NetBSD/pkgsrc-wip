# $NetBSD: Makefile,v 1.1 2014/02/18 21:20:51 jihbed Exp $

DISTNAME=	mahotas-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	https://pypi.python.org/packages/source/m/mahotas/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://luispedro.org/software/mahotas
COMMENT=	Mahotas: Computer Vision Library
LICENSE=	mit

USE_LANGUAGES=	c++

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
