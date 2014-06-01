# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:42 thomasklausner Exp $

DISTNAME=	pykrylov-0.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/p/pykrylov/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/dpo/pykrylov/tree/master
COMMENT=	Python package implementing common Krylov methods
LICENSE=	gnu-lgpl-v2.1

PYDISTUTILSPKG=	yes

USE_LANGUAGES=	# none

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
