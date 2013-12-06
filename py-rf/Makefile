# $NetBSD: Makefile,v 1.2 2013/12/06 00:14:25 jihbed Exp $

DISTNAME=	rf-0.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/r/rf/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/packages/source/r/rf/
COMMENT=	Receiver function calculation in seismology
LICENSE=	mit

USE_LANGUAGES=	# none

USE_LANGUAGES=	c fortran

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-geographiclib>=1.31:../../wip/py-geographiclib
DEPENDS+=	${PYPKGPREFIX}-obspy>=0.8.4:../../wip/py-obspy
DEPENDS+=	${PYPKGPREFIX}-toeplitz>=0.1.2:../../wip/py-toeplitz
.include "../../mk/bsd.pkg.mk"
