# $NetBSD: Makefile,v 1.1 2014/07/26 20:00:13 jihbed Exp $

DISTNAME=	msumastro-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/m/msumastro/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/mwcraig/msumastro
COMMENT=	Process FITS files
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
