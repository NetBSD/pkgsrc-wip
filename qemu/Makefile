# $NetBSD: Makefile,v 1.3 2004/09/07 21:10:49 hubertf Exp $
#

DISTNAME=		qemu-0.6.0
CATEGORIES=		emulators
MASTER_SITES=		http://fabrice.bellard.free.fr/qemu/

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://fabrice.bellard.free.fr/qemu/
COMMENT=		CPU emulator using dynamic translation

#PKG_SKIP_REASON=	unfinished / fails to build

CONFLICTS+=		qemu-bin-*

GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--interp-prefix=${PREFIX}/share/gnemul/qemu-%M

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
