# $NetBSD: Makefile,v 1.9 2004/09/30 12:32:06 thomasklausner Exp $
#

DISTNAME=		libXcursor-1.1.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.freedesktop.org/Software/xlibs
COMMENT=		Client-side cursor loading library for X

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	xcursor.pc.in

.include "../../wip/xproto/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXrender/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/Xfixes/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
