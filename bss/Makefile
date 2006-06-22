# $NetBSD: Makefile,v 1.3 2006/06/22 20:51:58 poppnk Exp $
#

DISTNAME=		bss-0.6
PKGREVISION=   1
CATEGORIES=		wip security
MASTER_SITES=		http://www.secuobs.com/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.secuobs.com/
COMMENT=		Bluetooth Stack Smasher

USE_TOOLS+=		pkg-config

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} -lbluetooth \
		${WRKSRC:Q}/bss.c -o ${WRKSRC:Q}/bss
	${CC} ${CFLAGS} ${LDFLAGS} -lbluetooth \
		${WRKSRC:Q}/replay_packet/replay_l2cap_packet.c \
		-o ${WRKSRC:Q}/replay_packet/replay_l2cap_packet


DOC_FILES=${WRKSRC}/doc/* ${WRKSRC}/README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/bss ${PREFIX:Q}/bin
	${INSTALL_PROGRAM} ${WRKSRC:Q}/replay_packet/replay_l2cap_packet \
		${PREFIX:Q}/bin/
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/doc/bss/
	${INSTALL_DATA} ${DOC_FILES} ${PREFIX:Q}/share/doc/bss/

.include "../../wip/bluez-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
