# $NetBSD: Makefile,v 1.2 2004/07/18 15:50:17 ppostma Exp $
#

DISTNAME=		PyPanel-1.2
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
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../wip/py-Xlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
