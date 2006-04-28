# $NetBSD: Makefile,v 1.11 2006/04/28 06:29:36 jeremy-c-reed Exp $
#

DISTNAME=		xtrans-1.0.0
CATEGORIES=		x11 net
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Network API translation layer to insulate X

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	xtrans.pc.in

.include "../../mk/bsd.pkg.mk"
