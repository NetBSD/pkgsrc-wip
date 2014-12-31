# $NetBSD: Makefile,v 1.3 2014/12/31 13:58:34 thomasklausner Exp $

DISTNAME=	msumastro-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/m/msumastro/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/mwcraig/msumastro
COMMENT=	Process FITS files
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-astropy>=0.3.1:../../wip/py-astropy

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-astropy

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
