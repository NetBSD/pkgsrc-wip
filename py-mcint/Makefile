# $NetBSD: Makefile,v 1.3 2012/11/14 00:16:14 othyro Exp $
#

DISTNAME=	mcint-0.1dev5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mcint/}
EXTRACT_SUFX=	.zip
#LICENSE=	CC BY-NC-SA 3.0

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/mcint/
COMMENT=	Simple tool to perform numerical integration using MC techniques

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
