# $NetBSD: Makefile,v 1.9 2005/09/07 16:24:57 leonardschmidt Exp $
#

DISTNAME=		libXtrans-0.1
PKGNAME=		xtrans-0.1
CATEGORIES=		x11 net
MASTER_SITES=		http://xlibs.freedesktop.org/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		Network API translation layer to insulate X

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	xtrans.pc.in

.include "../../mk/bsd.pkg.mk"
