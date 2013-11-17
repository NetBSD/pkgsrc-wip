# $NetBSD: Makefile,v 1.1 2013/11/17 22:21:02 jihbed Exp $

DISTNAME=	AQoPA-0.5.3
PKGNAME=	${PYPKGPREFIX}-aqopa-0.5.3
CATEGORIES=	security python
MASTER_SITES=	https://pypi.python.org/packages/source/A/AQoPA/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://qopml.org/aqopa/
COMMENT=	Automated Quality of Protection Analysis Tool for QoP-ML models
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
