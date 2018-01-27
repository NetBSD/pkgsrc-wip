# $NetBSD: Makefile,v 1.6 2012/11/12 16:26:51 othyro Exp $
#

DISTNAME=	scikits.timeseries-0.91.3
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S|s.|s_|}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pytseries/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pytseries.sourceforge.net/
COMMENT=	Time series manipulation
LICENSE=	modified-bsd

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
