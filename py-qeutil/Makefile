# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:45 thomasklausner Exp $

DISTNAME=	qeutil-0.1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=q/qeutil/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/jochym/qe-util
COMMENT=	Set of utilities for using Quantum-Espresso
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
