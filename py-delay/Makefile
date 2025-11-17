# $NetBSD: Makefile,v 1.1 2014/09/10 21:12:25 jihbed Exp $

DISTNAME=	pydelay-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math python
MASTER_SITES=	http://garr.dl.sourceforge.net/project/pydelay/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pydelay.sourceforge.net/
COMMENT=	Python tool for solving delay differential equations
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.0:../../math/py-scipy

USE_LANGUAGES=	# none

.include "../../wip/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
