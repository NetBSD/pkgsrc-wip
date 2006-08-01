# $NetBSD: Makefile,v 1.1.1.1 2006/08/01 04:13:41 dhowland Exp $
#

PKGNAME=		vncselector-1.6.1
DISTNAME=		vncselector_1.6.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vncselector/}

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://vncselector.sourceforge.net/
COMMENT=		Tool for managing VNC sessions

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++ fortran
USE_LIBTOOL=            yes
USE_TOOLS+=		gmake

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
