# $NetBSD$

DISTNAME=	backports_tarfile-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:C/_/./}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/backports_tarfile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/backports.tarfile
COMMENT=	Backport of CPython tarfile module
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
