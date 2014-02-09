# $NetBSD: Makefile,v 1.1 2014/02/09 20:34:18 jihbed Exp $

DISTNAME=	quantities-0.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/q/quantities/
EXTRACT_SUFX=	.zip#md5=75bb0571d220ea12abb31883b499f90c
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://packages.python.org/quantities
COMMENT=	Support for physical quantities with units, based on numpy
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
