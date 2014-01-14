# $NetBSD: Makefile,v 1.1 2014/01/14 21:15:08 jihbed Exp $

DISTNAME=	pyssp-0.1.6.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/p/pyssp/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://bitbucket.org/aihara/pyssp/
COMMENT=	Python speech signal processing library for education
LICENSE=	cc-by-sa-v3.0

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
.include "../../mk/bsd.pkg.mk"
