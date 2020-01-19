# $NetBSD: Makefile,v 1.3 2012/11/14 00:16:13 othyro Exp $
#

DISTNAME=	ATpy-0.9.6
PKGNAME=	${PYPKGPREFIX}-atpy-0.9.6
CATEGORIES=	math
MASTER_SITES=	http://cloud.github.com/downloads/atpy/atpy/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://atpy.github.com/
COMMENT=	Astronomical Tables in Python
LICENSE=	mit

PYDISTUTILSPKG=	yes
USE_LANGUAGES=	# none

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
