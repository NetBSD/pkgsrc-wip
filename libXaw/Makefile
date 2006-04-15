# $NetBSD: Makefile,v 1.2 2006/04/15 02:33:59 jeremy-c-reed Exp $
#

DISTNAME=		libXaw-1.0.1
CATEGORIES=		graphics x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X Athena Widgets Library from modular Xorg X11

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xaw6.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xaw7.pc.in
#TODO# PKGCONFIG_OVERRIDE+=	${WRKSRC}/xaw8.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3

# TODO: should this install all three versions? document in DESCR
# TODO:            Xprint is required to build libXaw.so.8.

.include "../../wip/xproto/buildlink3.mk"
.include "../../wip/xextproto/buildlink3.mk"
.include "../../wip/libICE/buildlink3.mk"
.include "../../wip/libSM/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXext/buildlink3.mk"
.include "../../wip/libXmu/buildlink3.mk"
.include "../../wip/libXpm/buildlink3.mk"
.include "../../wip/libXt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
