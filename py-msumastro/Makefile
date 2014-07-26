# $NetBSD: Makefile,v 1.2 2014/07/26 20:05:13 jihbed Exp $

DISTNAME=	msumastro-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/m/msumastro/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/mwcraig/msumastro
COMMENT=	Process FITS files
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-astropy>=0.3.1:../../wip/py-astropy

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
