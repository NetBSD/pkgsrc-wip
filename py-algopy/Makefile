# $NetBSD: Makefile,v 1.1.1.1 2011/03/20 23:59:05 jihbed Exp $
#

DISTNAME=	algopy-0.2.2
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/a/algopy/

MAINTAINER=	jihbed.esearch@gmail.com
HOMEPAGE=	http://packages.python.org/algopy
COMMENT=	Taylor Arithmetic Computation and Algorithmic Differentiation
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/algopy-0.2.2
USE_LANGUAGES=	# none

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
