# $NetBSD: Makefile,v 1.5 2006/02/04 12:54:56 poppnk Exp $
#

DISTNAME=		libbtctl-0.6.0
CATEGORIES=		net
MASTER_SITES=		http://ftp.gnome.org/pub/gnome/sources/libbtctl/0.6/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://usefulinc.com/software/gnome-bluetooth
COMMENT=		GObject Bluetooth controller

USE_TOOLS=gmake
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libbtctl.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/mono/libbtctl/libbtctl-sharp.pc.in

USE_PERL5=YES

GNU_CONFIGURE=		yes

ONLY_FOR_PLATFORM=Linux-*-*

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/bluez-libs/buildlink3.mk"
.include "../../comms/openobex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
