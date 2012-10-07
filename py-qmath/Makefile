# $NetBSD: Makefile,v 1.5 2012/10/07 13:57:29 asau Exp $
#

DISTNAME=	qmath-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/q/qmath/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/qmath
COMMENT= Provides a class for deal with quaternion algebra and 3D rotation
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/qmath-0.2.0

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
