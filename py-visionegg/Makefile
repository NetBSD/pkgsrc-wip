# $NetBSD: Makefile,v 1.1.1.1 2004/01/02 00:15:34 mpasternak Exp $
#

DISTNAME=		visionegg-0.9.9
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=visionegg/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://visionegg.sourceforge.net/
COMMENT=		Visual stimulus creation and control in Python

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
MAKE_ENV+=		PYVERSSUFFIX=${PYVERSSUFFIX}
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

.if exists(../../mk/opengl.buildlink2.mk) 
# see PR 23845 for details
.include "../../mk/opengl.buildlink2.mk"
.else
.include "../../graphics/MesaLib/buildlink2.mk"
.endif

.include "../../math/py-Numeric/buildlink2.mk"
.include "../../wip/py-game/buildlink2.mk"
.include "../../x11/py-Tk/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
