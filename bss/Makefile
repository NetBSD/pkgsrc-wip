# $NetBSD: Makefile,v 1.2 2006/02/17 21:46:42 rillig Exp $
#

DISTNAME=		bss-0.6
CATEGORIES=		security
MASTER_SITES=		http://www.secuobs.com/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.secuobs.com/
COMMENT=		Bluetooth Stack Smasher

USE_TOOLS+=		pkg-config
DOC_FILES=${WRKSRC}/doc/* ${WRKSRC}/README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/bss ${PREFIX:Q}/bin
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/doc/bss/
	${INSTALL_DATA} ${DOC_FILES} ${PREFIX:Q}/share/doc/bss/
	${INSTALL_DATA} ${WRKSRC:Q}/replay_packet/replay_l2cap_packet.c ${PREFIX:Q}/share/doc/bss/

.include "../../wip/bluez-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
