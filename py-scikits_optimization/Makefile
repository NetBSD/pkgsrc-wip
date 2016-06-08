# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:29 asau Exp $
#

DISTNAME=	scikits.optimization-0.1
PKGNAME=	${PYPKGPREFIX}-scikits_optimization-0.1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scikits.optimization/}
EXTRACT_SUFX=	.zip#md5=033ccd3056942d8a226aeb0eb8fbab45

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://projects.scipy.org/scipy/scikits
COMMENT=	Python module for numerical optimization
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
