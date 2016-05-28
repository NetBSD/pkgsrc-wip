# $NetBSD: Makefile,v 1.8 2012/10/07 17:41:43 asau Exp $
#

PKGNAME=		vncselector-1.6.1
DISTNAME=		vncselector_1.6.1
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vncselector/}

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://vncselector.sourceforge.net/
COMMENT=		Tool for managing VNC sessions


GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++ fortran77
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.if ${X11_TYPE} == "native"
.include "../../mk/x11.buildlink3.mk"
.else
.include "../../x11/libX11/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
