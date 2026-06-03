# $NetBSD$

DISTNAME=	mfusepy-3.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	filesystems python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mfusepy/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://pypi.org/project/mfusepy/
COMMENT=	Python bindings for the FUSE[23] APIs
LICENSE=	isc

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
