# $NetBSD: Makefile,v 1.4 2007/03/07 17:38:11 xtraeme Exp $
#

DISTNAME=		btfs-0.0.3
PKGNAME=		fusefs-btfs-0.0.3
CATEGORIES=		sysutils
MASTER_SITES=		http://www.mulliner.org/bluetooth/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.mulliner.org/bluetooth/btfs.php
COMMENT=		Bluetooth Filesystem for FUSE

MAKE_FILE=		makefile
WRKSRC=			${WRKDIR}/btfs/src/
USE_TOOLS+=		gmake
USE_LANGUAGES=		c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/btfs ${PREFIX}/bin/

.include "../../comms/openobex/buildlink3.mk"
.include "../../wip/bluez-libs/buildlink3.mk"
.include "../../mk/fuse/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
