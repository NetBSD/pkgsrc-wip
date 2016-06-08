# $NetBSD: Makefile,v 1.1 2014/07/22 18:42:18 jihbed Exp $

DISTNAME=	dimarray-0.1.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dimarray/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://dimarray.readthedocs.org
COMMENT=	Numpy array with labelled dimensions and axes, dimension
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none


.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
