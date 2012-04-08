# $NetBSD: Makefile,v 1.3 2012/04/08 19:09:50 thomasklausner Exp $
#

DISTNAME=	scikits.statsmodels-0.2.0
PKGNAME=	${PYPKGPREFIX}-scikits_statsmodels-0.2.0
CATEGORIES=	math
MASTER_SITES=	http://pypi.python.org/packages/source/s/scikits.statsmodels/
EXTRACT_SUFX=	.zip#md5=2cd76559b3bb49acc8e3baafdf3f402e

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://statsmodels.sourceforge.net/
COMMENT=	Statistical computations and models for use with SciPy
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
