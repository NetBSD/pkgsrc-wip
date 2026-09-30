# $NetBSD$

DISTNAME=	mfusepy-3.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	filesystems python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mfusepy/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://pypi.org/project/mfusepy/
COMMENT=	Python bindings for the FUSE[23] APIs
LICENSE=	isc

USE_LANGUAGES=	# none

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=77:../../devel/py-setuptools

# Upstream has many test dependencies, not expressed in pyproject.toml.
# At least:
#   loopback
#   memory
# https://github.com/mxmlnkn/mfusepy/issues/61

.include "../../lang/python/wheel.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
