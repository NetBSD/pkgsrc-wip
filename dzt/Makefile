# $NetBSD: Makefile,v 1.1.1.1 2003/07/04 03:09:36 poppnk Exp $
#

DISTNAME=	dzt-1.1.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dzt/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://dzt.sourceforge.net/
COMMENT=	Dzt is a Yet Another Tabbed GNOME Terminal

USE_GMAKE=	yes
USE_X11=	yes
USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes

.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
