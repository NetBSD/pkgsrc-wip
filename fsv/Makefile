# $NetBSD: Makefile,v 1.1.1.1 2003/08/19 06:48:09 xtraeme Exp $
#

DISTNAME=	fsv-0.9
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fsv/}

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://fsv.sourceforge.net/
COMMENT=	3D filesystem visualizer

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11=		yes

.include "../../x11/gtkglarea/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
