# $NetBSD: Makefile,v 1.2 2004/09/02 04:59:37 dhowland Exp $
#

DISTNAME=		qemu-0.6.0
CATEGORIES=		emulators
MASTER_SITES=		http://fabrice.bellard.free.fr/qemu/

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://fabrice.bellard.free.fr/qemu/
COMMENT=		CPU emulator using dynamic translation

#PKG_SKIP_REASON=	unfinished / fails to build

BUILD_DEPENDS+=		SDL>=1.2.7:../../devel/SDL
CONFLICTS+=		qemu-bin-*

GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

ONLY_FOR_PLATFORM=	NetBSD-*-i386

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--interp-prefix=${PREFIX}/share/gnemul/qemu-%M

.include "../../mk/bsd.pkg.mk"
