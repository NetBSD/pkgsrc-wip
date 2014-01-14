# $NetBSD: Makefile,v 1.1 2014/01/14 23:49:53 jihbed Exp $

DISTNAME=	otb-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/o/otb/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://bitbucket.org/forieux/otb/
COMMENT=	Utility functions for scientific numerical computation
LICENSE=	mit

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
