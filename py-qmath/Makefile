# $NetBSD: Makefile,v 1.6 2012/10/16 12:07:34 jihbed Exp $
#

DISTNAME=	qmath-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=q/qmath/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/qmath
COMMENT=	Provides a class for deal with quaternion algebra and 3D rotation
LICENSE=	gnu-gpl-v3 AND gnu-fdl-v1.2

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy

WRKSRC=		${WRKDIR}/qmath-0.3.0

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
