# $NetBSD: Makefile,v 1.1.1.1 2010/06/12 23:28:58 jihbed Exp $
#

DISTNAME=	pandas-0.2beta
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/beta//}
CATEGORIES=	math
MASTER_SITES=	http://pandas.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pandas.sourceforge.net/
COMMENT=	Pythonic cross-section, time series, and statistical analysis
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-dateutil>=1.5:../../time/py-dateutil

PKG_DESTDIR_SUPPORT=	user-destdir
PYDISTUTILSPKG=	yes


.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
