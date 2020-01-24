# $NetBSD: Makefile,v 1.5 2012/11/12 16:26:50 othyro Exp $
#

DISTNAME=	pypol-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pypol/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypol.sourceforge.net/
COMMENT=	Python module to manage monomials and polynomials
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-gmpy>=1.01:../../math/py-gmpy

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
