# $NetBSD: Makefile,v 1.2 2014/01/26 15:49:55 thomasklausner Exp $

DISTNAME=	Hamilton-0.1.0
PKGNAME=	${PYPKGPREFIX}-hamilton-0.1.0
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/H/Hamilton/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/packages/source/H/Hamilton/
COMMENT= Visualize and control mechanic systems through solving these systems
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.6:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-sympy>=0.7.2:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk
DEPENDS+=	${PYPKGPREFIX}-control-[0-9]*:../../wip/py-control

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
