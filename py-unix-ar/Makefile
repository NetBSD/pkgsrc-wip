# $NetBSD$

DISTNAME=	unix_ar-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/unix_ar/unix-ar/}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/unix_ar/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/getninjas/unix_ar
COMMENT=	AR file handling for Python (including .deb files)
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=44.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
