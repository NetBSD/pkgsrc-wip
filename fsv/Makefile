# $NetBSD: Makefile,v 1.4 2004/04/25 06:35:01 blef Exp $
#

DISTNAME=	fsv-0.9
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fsv/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://fsv.sourceforge.net/
COMMENT=	3D filesystem visualizer

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes

.include "../../x11/gtkglarea/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
