# $NetBSD: Makefile,v 1.5 2012/09/28 22:07:35 asau Exp $
#

DISTNAME=		evilvte-0.4.3
PKGREVISION=		2
CATEGORIES=		x11
MASTER_SITES=		http://www.calno.com/evilvte/

MAINTAINER=		roy@marples.name
HOMEPAGE=		http://www.calno.com/evilvte/
COMMENT=		VTE based, highly customizable terminal emulator

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
USE_TOOLS+=		gmake pkg-config
MAKE_FLAGS+=		OPTFLAGS="${CFLAGS}"

INSTALL_MAKE_FLAGS+=	mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../x11/vte/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
