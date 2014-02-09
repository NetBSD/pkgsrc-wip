# $NetBSD: Makefile,v 1.1 2014/02/09 20:24:03 jihbed Exp $

DISTNAME=	pymeigo-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/p/pymeigo/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.ebi.ac.uk/~cokelaer/pymeigo
COMMENT=	Python wrapper of MEIGOR, a R optimisation package
LICENSE=	gnu-lgpl-v2

DEPENDS+=	${PYPKGPREFIX}-rpy>=2.1.3:../../math/py-rpy
DEPENDS+=	${PYPKGPREFIX}-easydev>=0.6.3:../../wip/py-easydev

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
