# $NetBSD: Makefile,v 1.17 2012/10/07 13:57:32 asau Exp $
#

DISTNAME=	visionegg-0.9.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	graphics python
MASTER_SITES=	http://surfnet.dl.sourceforge.net/project/visionegg/visionegg/visionegg-0.9.9/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://visionegg.sourceforge.net/
COMMENT=	Visual stimulus creation and control in Python
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-Pyro>=3.4:../../devel/py-Pyro
DEPENDS+=	${PYPKGPREFIX}-OpenGL-[0-9]*:../../graphics/py-OpenGL

USE_LANGUAGES= c c++

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
MAKE_ENV+=		PYVERSSUFFIX=${PYVERSSUFFIX:Q}
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX:Q}

.include "../../devel/py-game/buildlink3.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
