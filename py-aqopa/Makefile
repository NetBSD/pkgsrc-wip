# $NetBSD: Makefile,v 1.2 2014/01/25 10:38:15 thomasklausner Exp $

DISTNAME=	AQoPA-0.5.3
PKGNAME=	${PYPKGPREFIX}-aqopa-0.5.3
CATEGORIES=	security python
MASTER_SITES=	https://pypi.python.org/packages/source/A/AQoPA/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://qopml.org/aqopa/
COMMENT=	Automated Quality of Protection Analysis Tool for QoP-ML models
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-wxWidgets

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
