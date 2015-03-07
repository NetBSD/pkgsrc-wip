# $NetBSD: Makefile,v 1.4 2015/03/07 22:18:24 jihbed Exp $

DISTNAME=	lea-2.1.0
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=     math python
MASTER_SITES=	https://pypi.python.org/packages/source/l/lea/
EXTRACT_SUFX=	.zip#md5=a5b891442410178c8770283f5f2e587a

MAINTAINER=     jihbed.research@gmail.com
HOMEPAGE=       http://code.google.com/p/lea/
COMMENT=        Discrete probability distributions in Python
LICENSE=        gnu-lgpl-v3


USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
