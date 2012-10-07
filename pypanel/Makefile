# $NetBSD: Makefile,v 1.16 2012/10/07 13:57:33 asau Exp $
#

DISTNAME=		PyPanel-2.4
PKGREVISION=		2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pypanel/}

MAINTAINER=		ccatrian@eml.cc
HOMEPAGE=		http://pypanel.sourceforge.net/
COMMENT=		Lightweight panel written in Python and C for X11

DEPENDS+=		${PYPKGPREFIX}-Xlib-[0-9]*:../../x11/py-Xlib

PYDISTUTILSPKG=		yes
PY_PATCHPLIST=		yes

SUBST_CLASSES+=		setup
SUBST_MESSAGE.setup=	Fixing LOCALBASE and X11BASE paths.
SUBST_STAGE.setup=	pre-patch
SUBST_FILES.setup=	setup.py
SUBST_SED.setup+=	-e 's|/usr/bin|${PREFIX}/bin|g'
SUBST_SED.setup+=	-e 's|/usr/X11R6|${X11BASE}|g'
SUBST_SED.setup+=	-e 's|/usr/lib|${PREFIX}/lib|g'

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
