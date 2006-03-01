# $NetBSD: Makefile,v 1.15 2006/03/01 19:23:09 jeremy-c-reed Exp $
#

DISTNAME=		xproto-7.0.4
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X protocol and ancillary headers from Xorg X11

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	xproto.pc.in
USE_LANGUAGES=		# empty

.include "../../mk/bsd.pkg.mk"
