# $NetBSD: Makefile,v 1.4 2015/07/11 00:36:05 jihbed Exp $

DISTNAME=	msumastro-0.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/msumastro/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/mwcraig/msumastro
COMMENT=	Process FITS files
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-astropy>=0.4.6:../../wip/py-astropy
DEPENDS+=	${PYPKGPREFIX}-ccdproc>=0.3.1:../../wip/py-ccdproc

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-astropy

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
