# $NetBSD: Makefile,v 1.6 2005/04/11 21:09:37 tvierling Exp $
#

DISTNAME=		PyPanel-2.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pypanel/}

MAINTAINER=		ccatrian@eml.cc
HOMEPAGE=		http://pypanel.sourceforge.net/
COMMENT=		Lightweight panel written in Python and C for X11

PYDISTUTILSPKG=		yes
PY_PATCHPLIST=  	yes
USE_X11=		yes

SUBST_CLASSES+=		setup
SUBST_MESSAGE.setup=	"Fixing LOCALBASE and X11BASE paths."
SUBST_STAGE.setup=	post-patch
SUBST_FILES.setup=	setup.py
SUBST_SED.setup+=	-e 's|/usr/bin|${LOCALBASE}/bin|g'
SUBST_SED.setup+=	-e 's|/usr/X11R6|${X11BASE}|g'
SUBST_SED.setup+=	-e 's|/usr/lib|${LOCALBASE}/lib|g'

PYTHON_VERSIONS_ACCEPTED=	24 23 22

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/py-Xlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
