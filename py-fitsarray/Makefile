# $NetBSD: Makefile,v 1.3 2014/01/19 20:34:14 thomasklausner Exp $

DISTNAME=	fitsarray-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fitsarray/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi?%3Aaction=search&term=fitsarray&submit=search
COMMENT=	Ndarray subclass with a fits header


DEPENDS+=	${PYPKGPREFIX}-fits>=2.3.1:../../graphics/py-fits

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
