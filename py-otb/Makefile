# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:44 thomasklausner Exp $

DISTNAME=	otb-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=o/otb/}

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
