# $NetBSD: Makefile,v 1.6 2012/09/24 17:14:42 asau Exp $
#

DISTNAME=		bss-0.6
PKGREVISION=   1
CATEGORIES=		security
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
	${INSTALL_PROGRAM} ${WRKSRC:Q}/bss ${DESTDIR:Q}${PREFIX:Q}/bin
	${INSTALL_PROGRAM} ${WRKSRC:Q}/replay_packet/replay_l2cap_packet \
		${DESTDIR:Q}${PREFIX:Q}/bin/
	${INSTALL_DATA_DIR} ${DESTDIR:Q}${PREFIX:Q}/share/doc/bss/
	${INSTALL_DATA} ${DOC_FILES} ${DESTDIR:Q}${PREFIX:Q}/share/doc/bss/

.include "../../wip/bluez-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
