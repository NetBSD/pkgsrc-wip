# $NetBSD: Makefile,v 1.2 2012/10/07 11:54:35 asau Exp $
#

DISTNAME=	fitsarray-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/f/fitsarray/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi?%3Aaction=search&term=fitsarray&submit=search
COMMENT=	Ndarray subclass with a fits header


DEPENDS+=	${PYPKGPREFIX}-pyfits>=2.3.1:../../graphics/py-pyfits

WRKSRC=		${WRKDIR}/fitsarray-0.2.0

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
