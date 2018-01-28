# $NetBSD: Makefile,v 1.7 2012/11/25 23:32:09 othyro Exp $
#

DISTNAME=	bss-0.6
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.secuobs.com/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.secuobs.com/
COMMENT=		Bluetooth Stack Smasher

USE_TOOLS+=		pkg-config

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} -lbluetooth \
		${WRKSRC}/bss.c -o ${WRKSRC}/bss
	${CC} ${CFLAGS} ${LDFLAGS} -lbluetooth \
		${WRKSRC}/replay_packet/replay_l2cap_packet.c \
		-o ${WRKSRC}/replay_packet/replay_l2cap_packet


DOC_FILES=	${WRKSRC}/doc/* ${WRKSRC}/README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bss ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/replay_packet/replay_l2cap_packet \
		${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/bss/
	${INSTALL_DATA} ${DOC_FILES} ${DESTDIR}${PREFIX}/share/doc/bss/

.include "../../wip/bluez-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
