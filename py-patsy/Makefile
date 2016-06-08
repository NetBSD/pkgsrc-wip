# $NetBSD: Makefile,v 1.1 2014/07/26 10:10:43 jihbed Exp $

DISTNAME=	patsy-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/patsy/}
EXTRACT_SUFX=	.zip#md5=7545518b413136ba8343dcebea07e5e2

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	${MASTER_SITE_PYPI:=p/patsy/}
COMMENT=	Python package for describing statistical models
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
