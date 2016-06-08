# $NetBSD: Makefile,v 1.3 2014/05/09 07:38:45 thomasklausner Exp $

DISTNAME=	AQoPA-0.5.3
PKGNAME=	${PYPKGPREFIX}-aqopa-0.5.3
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=A/AQoPA/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://qopml.org/aqopa/
COMMENT=	Automated Quality of Protection Analysis Tool for QoP-ML models
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-wxWidgets

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
