# $NetBSD: Makefile,v 1.4 2003/05/07 17:37:39 lsed Exp $
#

DISTNAME=	celestia-1.3.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=celestia/}

MAINTAINER=	cesar_catrian@yahoo.com
HOMEPAGE=	http://www.shatters.net/celestia/
COMMENT=	Free real time space simulator in three dimensions

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X11=	YES

.include "../../x11/gtkglarea/buildlink2.mk"
.include "../../graphics/glut/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
