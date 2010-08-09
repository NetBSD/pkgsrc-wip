# $NetBSD: Makefile,v 1.1.1.1 2010/08/09 21:52:59 jihbed Exp $
#

DISTNAME=	pypol-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://garr.dl.sourceforge.net/project/pypol/pypol/0.5%20Eratosthenes/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypol.sourceforge.net/
COMMENT=	Python module to manage monomials and polynomials
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../wip/py-gmpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
