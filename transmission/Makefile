# $NetBSD: Makefile,v 1.2 2006/07/27 16:55:56 tnn2 Exp $
#

TRANSMISSION_VERSION=	0.6.1
DISTNAME=		Transmission-${TRANSMISSION_VERSION}
PKGNAME=		transmission-${TRANSMISSION_VERSION}
CATEGORIES=		net x11
MASTER_SITES=		http://download.m0k.org/transmission/files/

MAINTAINER=		tnn+nbsd@nygren.pp.se
HOMEPAGE=		http://transmission.m0k.org/
COMMENT=		BitTorrent client using GTK2+

HAS_CONFIGURE=		YES
USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	--prefix=${PREFIX}

.include "../../security/openssl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
