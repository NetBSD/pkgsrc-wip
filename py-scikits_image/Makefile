# $NetBSD: Makefile,v 1.1.1.1 2011/01/17 22:18:27 jihbed Exp $
#

DISTNAME=	scikits.image-0.2.2
PKGNAME=	${PYPKGPREFIX}-scikits_talkbox-0.2.5
CATEGORIES=	graphics python
MASTER_SITES=	http://pypi.python.org/packages/source/s/scikits.image/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/packages/source/s/scikits.image/
COMMENT=	Image processing routines for SciPy
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/scikits.image-0.2.2

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
