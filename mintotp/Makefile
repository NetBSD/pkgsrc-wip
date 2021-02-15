# $NetBSD$

DISTNAME=	mintotp-0.3.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mintotp/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/susam/mintotp
COMMENT=	Minimal TOTP Generator
LICENSE=	mit

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	mintotp.py

# Only for Python 3
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
