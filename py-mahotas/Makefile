# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:43 thomasklausner Exp $

DISTNAME=	mahotas-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mahotas/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://luispedro.org/software/mahotas
COMMENT=	Mahotas: Computer Vision Library
LICENSE=	mit

USE_LANGUAGES=	c++

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
