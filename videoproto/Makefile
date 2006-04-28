# $NetBSD: Makefile,v 1.3 2006/04/28 06:29:36 jeremy-c-reed Exp $
#

DISTNAME=		videoproto-2.2.2
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
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
