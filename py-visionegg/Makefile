# $NetBSD: Makefile,v 1.23 2014/05/09 07:38:51 thomasklausner Exp $

DISTNAME=	visionegg-0.9.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=visionegg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://visionegg.sourceforge.net/
COMMENT=	Visual stimulus creation and control in Python
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-Pyro4>=3.4:../../devel/py-Pyro
DEPENDS+=	${PYPKGPREFIX}-OpenGL-[0-9]*:../../graphics/py-OpenGL
DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

USE_LANGUAGES=	c c++

MAKE_ENV+=		PYVERSSUFFIX=${PYVERSSUFFIX:Q}

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-Numeric
REPLACE_PYTHON+=		check-config.py
REPLACE_PYTHON+=		test/display_dc_restoration.py
REPLACE_PYTHON+=		test/opengl_info.py

.include "../../devel/py-game/buildlink3.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
