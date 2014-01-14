# $NetBSD: Makefile,v 1.1 2014/01/14 22:17:46 jihbed Exp $

DISTNAME=	pykrylov-0.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/p/pykrylov/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/dpo/pykrylov/tree/master
COMMENT=	Python package implementing common Krylov methods
LICENSE=	gnu-lgpl-v2.1

PYDISTUTILSPKG=	yes

USE_LANGUAGES=	# none

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
