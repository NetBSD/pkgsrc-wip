# $NetBSD: Makefile,v 1.4 2012/10/07 13:57:28 asau Exp $
#

DISTNAME=	pypol-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://garr.dl.sourceforge.net/project/pypol/pypol/0.5%20Eratosthenes/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypol.sourceforge.net/
COMMENT=	Python module to manage monomials and polynomials
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-gmpy>=1.01:../../math/py-gmpy

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
