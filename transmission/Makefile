# $NetBSD: Makefile,v 1.1.1.1 2006/03/25 13:59:43 tnn2 Exp $
#

TRANSMISSION_VERSION=	0.5
DISTNAME=		Transmission-${TRANSMISSION_VERSION}
PKGNAME=		transmission-${TRANSMISSION_VERSION}
CATEGORIES=		net x11
MASTER_SITES=		http://download.m0k.org/transmission/files/

MAINTAINER=		tnn+nbsd@nygren.pp.se
HOMEPAGE=		http://transmission.m0k.org/
COMMENT=		BitTorrent client using GTK2+

HAS_CONFIGURE=		YES
USE_TOOLS+=		pkg-config
BUILD_DEPENDS+=		jam>=2.5:../../devel/jam

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--openssl-prefix=${LOCALBASE:Q}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${LOCALBASE:Q}/bin/jam

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/transmissioncli ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/gtk/transmission-gtk ${PREFIX}/bin

.include "../../security/openssl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
