# $NetBSD$

DISTNAME=	python_debian-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python_//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python_debian/}

MAINTAINER=	pkgsrc-users@yahoo.com
HOMEPAGE=	https://salsa.debian.org/python-debian-team/python-debian
COMMENT=	Python modules to work with Debian-related data formats
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-chardet>=3.0.4:../../converters/py-chardet

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	src/debian/doc-debtags

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
