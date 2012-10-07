# $NetBSD: Makefile,v 1.3 2012/10/07 13:57:32 asau Exp $
#

DISTNAME=	uncertainties-1.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	physics python
MASTER_SITES=	http://pypi.python.org/packages/source/u/uncertainties/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://packages.python.org/uncertainties/
COMMENT=	Support for physical quantities with units, based on numpy
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/uncertainties-1.7.1

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
