# $NetBSD: Makefile,v 1.3 2012/04/08 19:09:51 thomasklausner Exp $
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

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
