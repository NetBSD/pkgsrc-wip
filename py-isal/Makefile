# $NetBSD$

DISTNAME=	isal-1.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_PYPI:=i/isal/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pycompression/python-isal
COMMENT=	Faster zlib and gzip compatible compression and decompression
LICENSE=	python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-versioningit-[0-9]*:../../devel/py-versioningit

USE_TOOLS+=	gmake

.include "../../wip/isa-l/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
