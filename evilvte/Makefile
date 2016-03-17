# $NetBSD: Makefile,v 1.6 2012/11/13 20:09:29 othyro Exp $
#

DISTNAME=		evilvte-0.5.1
CATEGORIES=		x11
MASTER_SITES=		http://www.calno.com/evilvte/

MAINTAINER=		roy@marples.name
HOMEPAGE=		http://www.calno.com/evilvte/
COMMENT=		VTE based, highly customizable terminal emulator
LICENSE=		gnu-gpl-v2

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
USE_TOOLS+=		gmake pkg-config
MAKE_FLAGS+=		OPTFLAGS=${CFLAGS:Q}
BUILD_TARGET=		evilvte

INSTALL_MAKE_FLAGS+=	mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1


.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
