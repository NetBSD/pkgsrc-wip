# $NetBSD: Makefile,v 1.1.1.1 2004/03/19 10:44:49 xtraeme Exp $
#

DISTNAME=		matchbox-desktop-0.8
CATEGORIES=		wm
MASTER_SITES=		http://matchbox.handhelds.org/sources/matchbox-desktop/0.8/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://matchbox.handhelds.org/sources/matchbox-desktop/0.8/
COMMENT=		Desktop manager for Matchbox window manager		

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE=     ${WRKSRC}/matchbox-desktop.pc.in

CONFIGURE_ARGS+=	--enable-startup-notification

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../wip/libmatchbox/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
