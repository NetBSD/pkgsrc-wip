# $NetBSD: Makefile,v 1.2 2012/04/08 19:09:50 thomasklausner Exp $
#

DISTNAME=	qmath-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/q/qmath/

MAINTAINER=	jihbed.resarch@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/qmath
COMMENT= Provides a class for deal with quaternion algebra and 3D rotation
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/qmath-0.2.0

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_ACCEPTED=		31 27 26 25

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
