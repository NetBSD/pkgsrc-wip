# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:29 asau Exp $
#

DISTNAME=	scikits.image-0.2.2
PKGNAME=	${PYPKGPREFIX}-scikits_talkbox-0.2.5
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scikits.image/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://files.pythonhosted.org/packages/source/s/scikits.image/
COMMENT=	Image processing routines for SciPy
LICENSE=	modified-bsd

WRKSRC=	${WRKDIR}/scikits.image-0.2.2

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
