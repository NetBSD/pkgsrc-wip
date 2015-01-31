# $NetBSD: Makefile,v 1.3 2015/01/31 23:26:31 jihbed Exp $

DISTNAME=	lea-2.0.0-beta.6
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=     math python
MASTER_SITES=	https://pypi.python.org/packages/source/l/lea/
EXTRACT_SUFX=	.zip#md5=a9f09d8372fdc2d4fbd959bcabff0b3e

MAINTAINER=     jihbed.research@gmail.com
HOMEPAGE=       http://code.google.com/p/lea/
COMMENT=        Discrete probability distributions in Python
LICENSE=        gnu-lgpl-v3

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
