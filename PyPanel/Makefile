# $NetBSD: Makefile,v 1.4 2004/12/14 12:02:13 cetrox Exp $
#

DISTNAME=		PyPanel-2.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pypanel/}

MAINTAINER=		ccatrian@eml.cc
HOMEPAGE=		http://pypanel.sourceforge.net/
COMMENT=		Lightweight panel written in Python and C for X11

PYDISTUTILSPKG=		yes
PY_PATCHPLIST=  	yes
USE_BUILDLINK3= 	yes
USE_X11=		yes

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../x11/py-Xlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
