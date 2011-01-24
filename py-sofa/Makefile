# $NetBSD: Makefile,v 1.1.1.1 2011/01/24 09:26:54 jihbed Exp $
#

DISTNAME=	pysofa-0.1.0a2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	astronomy python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pysofa/

MAINTAINER=	Ijihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/pysofa/
COMMENT=	Python ctypes wrapper around the SOFA astronomical library
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/pysofa-0.1.0a2

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../devel/py-ctypes/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
