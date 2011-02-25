# $NetBSD: Makefile,v 1.3 2011/02/25 09:47:48 thomasklausner Exp $
#

DISTNAME=	brian-1.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/b/brian/
EXTRACT_SUFX=	.zip#md5=1061bf5db014c9194c232e37b5715e46

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.briansimulator.org/
COMMENT=	Simulator for spiking neural networks
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-sympy>=0.6.5:../../math/py-sympy

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
PYDISTUTILSPKG= yes

PYTHON_VERSIONS_ACCEPTED= 27 26 25

.include "../../devel/py-game/buildlink3.mk"
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
