# $NetBSD: Makefile,v 1.1.1.1 2005/11/10 03:38:53 jeremy-c-reed Exp $
#

DISTNAME=		xineramaproto-1.1.1
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/X11R7.0-RC1/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Xinerama extension headers from X.org

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xineramaproto.pc.in
USE_LANGUAGES=		# empty

BUILDLINK_DEPMETHOD.libX11?=	build # uses headers
.include "../../wip/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
