# $NetBSD: Makefile,v 1.2 2012/10/06 17:13:33 asau Exp $
#

DISTNAME=	ATpy-0.9.6
PKGNAME=	${PYPKGPREFIX}-atpy-0.9.6
CATEGORIES=	science
MASTER_SITES=	http://cloud.github.com/downloads/atpy/atpy/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://atpy.github.com/
COMMENT=	Astronomical Tables in Python
LICENSE=	mit

PYDISTUTILSPKG=	yes
USE_LANGUAGES=	# none

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
