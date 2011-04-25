# $NetBSD: Makefile,v 1.2 2011/04/25 21:00:36 jihbed Exp $
#

DISTNAME=	algopy-0.3.0
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/a/algopy/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://packages.python.org/algopy
COMMENT=	Taylor Arithmetic Computation and Algorithmic Differentiation
LICENSE=	modified-bsd

#DEPENDS+=	${PYPKGPREFIX}-nose>=0.11.3:../../devel/py-nose

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/algopy-0.3.0

USE_LANGUAGES=	# none

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
