# $NetBSD: Makefile,v 1.9 2004/05/13 23:08:17 blef Exp $
#

DISTNAME=		libICE-6.3.1
PKGREVISION=		1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.freedesktop.org/software/xlibs
COMMENT=		Inter Client Exchange (ICE) library for X

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	ice.pc.in

.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXau/buildlink3.mk"
.include "../../wip/xproto/buildlink3.mk"
.include "../../wip/xtrans/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
