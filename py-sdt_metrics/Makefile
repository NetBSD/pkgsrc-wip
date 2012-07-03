# $NetBSD: Makefile,v 1.1.1.1 2012/07/03 14:14:54 jihbed Exp $
#

DISTNAME=	sdt_metrics-0.1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/s/sdt_metrics/
EXTRACT_SUFX=	.zip#md5=8f5b2a4ad73ec62c78872d2d3b509be2

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/sdt-metrics/
COMMENT=	Signal Detection Theory (SDT) metrics for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
