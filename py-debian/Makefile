# $NetBSD$

DISTNAME=	python-debian-0.1.38
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-debian/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://salsa.debian.org/python-debian-team/python-debian
COMMENT=	Python modules to work with Debian-related data formats
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-chardet>=3.0.4:../../converters/py-chardet

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
