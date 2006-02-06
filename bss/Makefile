# $NetBSD: Makefile,v 1.1.1.1 2006/02/06 23:37:25 poppnk Exp $
#

DISTNAME=		bss-0.6
CATEGORIES=		wip security
MASTER_SITES=		http://www.secuobs.com/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.secuobs.com/
COMMENT=		Bluetooth Stack Smasher

USE_TOOLS+=		pkg-config

DOC_FILES=${WRKSRC}/doc/* ${WRKSRC}/README
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bss ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bss/
	${INSTALL_DATA} ${DOC_FILES} ${PREFIX}/share/doc/bss/
	${INSTALL_DATA} ${WRKSRC}/replay_packet/replay_l2cap_packet.c ${PREFIX}/share/doc/bss/

.include "../../wip/bluez-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
