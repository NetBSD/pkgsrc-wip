# $NetBSD: Makefile,v 1.1.1.1 2004/09/02 01:27:45 dhowland Exp $
#

DISTNAME=		qemu-0.6.0
CATEGORIES=		emulators
MASTER_SITES=		http://fabrice.bellard.free.fr/qemu/

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://fabrice.bellard.free.fr/qemu/
COMMENT=		CPU emulator using dynamic translation

PKG_SKIP_REASON=        unfinished / fails to build

CONFLICTS+=             qemu-bin-*

GNU_CONFIGURE=          yes

ONLY_FOR_PLATFORM=      NetBSD-*-i386

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
