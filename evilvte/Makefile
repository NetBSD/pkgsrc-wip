# $NetBSD: Makefile,v 1.1 2008/11/27 13:04:15 rsmarples Exp $
#

DISTNAME=		evilvte-0.4.3
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
