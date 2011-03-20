# $NetBSD: Makefile,v 1.1.1.1 2011/03/20 22:21:46 jihbed Exp $
#

DISTNAME=	fitsarray-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/f/fitsarray/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi?%3Aaction=search&term=fitsarray&submit=search
COMMENT=	Ndarray subclass with a fits header


DEPENDS+=	${PYPKGPREFIX}-pyfits>=2.3.1:../../graphics/py-pyfits

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/fitsarray-0.2.0

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
