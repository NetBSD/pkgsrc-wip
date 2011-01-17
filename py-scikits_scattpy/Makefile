# $NetBSD: Makefile,v 1.1.1.1 2011/01/17 22:19:36 jihbed Exp $
#

DISTNAME=	scikits.scattpy-0.1.0
PKGNAME=	${PYPKGPREFIX}-scikits_scattpy-0.1.0
CATEGORIES=	math
MASTER_SITES=	http://pypi.python.org/packages/source/s/scikits.scattpy/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://scattpy.github.com/
COMMENT=	Light Scattering methods for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/scikits.scattpy-0.1.0
USE_LANGUAGES=	c fortran

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
