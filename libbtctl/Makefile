# $NetBSD: Makefile,v 1.1.1.1 2004/11/11 15:10:06 poppnk Exp $
#

DISTNAME=		libbtctl-0.4.1
CATEGORIES=		wip net
MASTER_SITES=		http://downloads.usefulinc.com/libbtctl/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://downloads.usefulinc.com/libbtctl/
COMMENT=		GObject Bluetooth controller

USE_BUILDLINK3=		yes
USE_GNU_TOOLS=make
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libbtctl.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/mono/libbtctl/libbtctl-sharp.pc.in

USE_PERL5=YES

GNU_CONFIGURE=		yes

ONLY_FOR_PLATFORM=Linux-*-*

.include "../../devel/glib2/buildlink3.mk"
.include "../../wip/bluez-libs/buildlink3.mk"
.include "../../comms/openobex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
