# $NetBSD: Makefile,v 1.1 2014/03/21 22:08:33 jihbed Exp $

DISTNAME=	sode-0.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sode/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/oscarbenjamin/sode
COMMENT=	Python/Cython lib for solving Stochastic Ordinary Differential Equations
LICENSE=	gnu-gpl-v3

PYDISTUTILSPKG=	yes
USE_TOOLS+=	bash

REPLACE_BASH+=	scripts/sode-time

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
