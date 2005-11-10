# $NetBSD: Makefile,v 1.1.1.1 2005/11/10 03:10:13 jeremy-c-reed Exp $
#

DISTNAME=		videoproto-2.2.1
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/X11R7.0-RC1/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Video extension headers from modular X.org X11

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/videoproto.pc.in
GNU_CONFIGURE=		yes

BUILDLINK_DEPMETHOD.libX11?=        build # uses headers
.include "../../wip/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
