# $NetBSD: Makefile,v 1.80 2021/07/25 20:42:33 leot Exp $

DISTNAME=	base45-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/base45/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kirei/python-base45
COMMENT=	Python Base45 Encoder/Decoder
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

# Only for Python 3
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
