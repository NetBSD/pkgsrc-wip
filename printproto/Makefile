# $NetBSD: Makefile,v 1.1.1.1 2006/04/29 03:52:54 jeremy-c-reed Exp $
#

DISTNAME=		printproto-1.0.3
CATEGORIES=		x11 print
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/releases/individual/proto/
COMMENT=		Print extension headers from X.org

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	printproto.pc.in

# maybe depend on at least xproto

.include "../../mk/bsd.pkg.mk"
