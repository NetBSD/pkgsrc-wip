# $NetBSD: Makefile,v 1.1 2014/10/03 18:48:15 jihbed Exp $

DISTNAME=	xcal_raman-0.1.5
PKGNAME=	${PYPKGPREFIX}-xcal-raman-0.1.5
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xcal_raman/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/xcal_raman
COMMENT=	Module for x-axis calibration of Raman spectrometers
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # as of 0.1.5

.include "../../lang/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
