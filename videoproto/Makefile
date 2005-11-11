# $NetBSD: Makefile,v 1.2 2005/11/11 23:22:12 jeremy-c-reed Exp $
#

DISTNAME=		videoproto-2.2.1
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/X11R7.0-RC1/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Video extension headers from modular X.org X11

PKGCONFIG_OVERRIDE+=	${WRKSRC}/videoproto.pc.in
GNU_CONFIGURE=		yes
USE_LANGUAGES=		# empty

BUILDLINK_DEPMETHOD.libX11?=        build # uses headers
.include "../../wip/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
