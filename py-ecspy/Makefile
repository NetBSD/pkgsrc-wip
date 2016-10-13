# $NetBSD: Makefile,v 1.4 2014/01/12 09:45:47 thomasklausner Exp $

DISTNAME=	ecspy-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/ecspy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://ecspy.googlecode.com/
COMMENT=	Framework for creating evolutionary computations in Python
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_ACCEPTED=	27

DEPENDS+=	${PYPKGPREFIX}-pp>=1.6.0:../../wip/py-pp

USE_LANGUAGES=	# none

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
