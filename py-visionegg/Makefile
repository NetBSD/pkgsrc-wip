# $NetBSD: Makefile,v 1.9 2006/06/12 16:28:59 thomasklausner Exp $
#

DISTNAME=		visionegg-0.9.9
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=visionegg/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://visionegg.sourceforge.net/
COMMENT=		Visual stimulus creation and control in Python

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
MAKE_ENV+=		PYVERSSUFFIX=${PYVERSSUFFIX:Q}
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX:Q}

.if exists(../../mk/opengl.buildlink3.mk)
# see PR 23845 for details
.include "../../mk/opengl.buildlink3.mk"
.else
.include "../../graphics/MesaLib/buildlink3.mk"
.endif

.include "../../math/py-Numeric/buildlink3.mk"
.include "../../devel/py-game/buildlink3.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
