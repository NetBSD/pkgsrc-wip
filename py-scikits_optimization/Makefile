# $NetBSD: Makefile,v 1.1.1.1 2011/01/17 22:22:47 jihbed Exp $
#

DISTNAME=	scikits.optimization-0.1
PKGNAME=	${PYPKGPREFIX}-scikits_optimization-0.1
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/s/scikits.optimization/
EXTRACT_SUFX=	.zip#md5=033ccd3056942d8a226aeb0eb8fbab45

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://projects.scipy.org/scipy/scikits
COMMENT=	Python module for numerical optimization
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
