# $NetBSD: Makefile,v 1.4 2012/05/11 13:19:28 noud4 Exp $
#

DISTNAME=	scikits.timeseries-0.91.3
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S|s.|s_|}
PKGREVISION=	1
CATEGORIES= math python
MASTER_SITES=	http://garr.dl.sourceforge.net/project/pytseries/scikits.timeseries/${PKGVERSION_NOREV}/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pytseries.sourceforge.net/
COMMENT=	Time series manipulation
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
