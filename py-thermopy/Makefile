# $NetBSD: Makefile,v 1.4 2012/10/07 13:57:31 asau Exp $
#

DISTNAME=	thermopy-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/thermopy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://packages.python.org/thermopy
COMMENT=	Some utilities for Thermodynamics and Thermochemistry
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree

WRKSRC=		${WRKDIR}/thermopy-0.3
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
