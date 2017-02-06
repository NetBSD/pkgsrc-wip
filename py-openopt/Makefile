# $NetBSD: Makefile,v 1.7 2015/02/08 21:45:50 jihbed Exp $

DISTNAME=	openopt-0.5404
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/openopt/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://openopt.org/Welcome
COMMENT=	Python module for numerical optimization
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
