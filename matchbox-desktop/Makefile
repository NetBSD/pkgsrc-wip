# $NetBSD: Makefile,v 1.7 2004/09/23 05:59:53 jlamwww Exp $
#

DISTNAME=	matchbox-desktop-0.8
CATEGORIES=	x11
MASTER_SITES=	http://matchbox.handhelds.org/sources/matchbox-desktop/0.8/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://matchbox.handhelds.org/
COMMENT=	Desktop manager for Matchbox

USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE=	matchbox-desktop.pc.in

CONFIGURE_ARGS+=	--enable-startup-notification

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../wip/libmatchbox/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
