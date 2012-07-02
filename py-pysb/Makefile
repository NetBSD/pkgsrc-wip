# $NetBSD: Makefile,v 1.1.1.1 2012/07/02 10:35:04 jihbed Exp $
#

DISTNAME=	pysb-0.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pysb/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pysb.org/
COMMENT=	Python Systems Biology modeling framework

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-sympy>=0.7.1:../../math/py-sympy

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/pysb-0.1.5

PYDISTUTILSPKG=	yes
USE_LANGUAGES=	# none

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
