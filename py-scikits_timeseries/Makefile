# $NetBSD: Makefile,v 1.1.1.1 2011/01/17 22:21:34 jihbed Exp $
#

DISTNAME=	scikits.timeseries-0.91.3
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-scikits_timeseries-0.91.3
CATEGORIES= math python
MASTER_SITES=	http://garr.dl.sourceforge.net/project/pytseries/scikits.timeseries/0.91.3/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pytseries.sourceforge.net/
COMMENT=	Time series manipulation
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED= 26 25 24

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
