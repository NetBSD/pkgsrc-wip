# $NetBSD: Makefile,v 1.1.1.1 2004/07/13 04:07:33 cetrox Exp $
#

DISTNAME=		PyPanel-1.2
CATEGORIES=		wip
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
