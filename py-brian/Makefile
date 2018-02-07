# $NetBSD: Makefile,v 1.6 2013/06/04 07:45:22 thomasklausner Exp $

DISTNAME=	brian-1.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/brian/}
EXTRACT_SUFX=	.zip#md5=1061bf5db014c9194c232e37b5715e46

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.briansimulator.org/
COMMENT=	Simulator for spiking neural networks
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-sympy>=0.6.5:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

USE_LANGUAGES=	c c++
PYDISTUTILSPKG=	yes

.include "../../devel/py-game/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
