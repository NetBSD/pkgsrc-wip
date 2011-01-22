# $NetBSD: Makefile,v 1.1.1.1 2011/01/22 16:18:40 jihbed Exp $
#

DISTNAME=	scikits.datasmooth-0.5
PKGNAME=	${PYPKGPREFIX}-scikits_datasmooth-0.5
CATEGORIES=	science python
MASTER_SITES=	http://pypi.python.org/packages/source/s/scikits.datasmooth/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://scikits.appspot.com/
COMMENT=	Scikits data smoothing package
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
