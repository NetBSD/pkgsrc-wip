# $NetBSD$

DISTNAME=	python-potr-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	python devel security
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-potr/}

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://github.com/python-otr/pure-python-otr
COMMENT=	Off-The-Record protocol implementation in Python
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-crypto-[0-9]*:../../security/py-crypto

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
