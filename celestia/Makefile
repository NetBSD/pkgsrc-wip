# $NetBSD: Makefile,v 1.2 2003/04/13 12:52:30 cjep Exp $
#

DISTNAME=	celestia-1.2.4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=celestia/}

MAINTAINER=	cesar_catrian@yahoo.com
HOMEPAGE=	http://www.shatters.net/celestia/
COMMENT=	Free real time space simulator in three dimensions

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES

.include "../../x11/gtkglarea/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../graphics/glut/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
