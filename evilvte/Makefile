# $NetBSD: Makefile,v 1.2 2009/06/11 08:10:32 thomasklausner Exp $
#

DISTNAME=		evilvte-0.4.3
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		http://www.calno.com/evilvte/

MAINTAINER=		roy@marples.name
HOMEPAGE=		http://www.calno.com/evilvte/
COMMENT=		VTE based, highly customizable terminal emulator

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
USE_TOOLS+=		gmake pkg-config
MAKE_FLAGS+=		OPTFLAGS="${CFLAGS}"

INSTALL_MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}/man1

.include "../../x11/vte/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
