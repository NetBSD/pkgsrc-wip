# $NetBSD: Makefile,v 1.5 2003/11/25 15:16:31 adrian_p Exp $
#

DISTNAME=	arpd-0.2
PKGNAME=	honeyd-arpd-0.2
WRKSRC=		${WRKDIR}/arpd
CATEGORIES=	security net
MASTER_SITES=	http://niels.xtdnet.nl/honeyd/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://niels.xtdnet.nl/honeyd/index.php
COMMENT=	ARP daemon for honeyd

USE_PKGINSTALL= YES
RCD_SCRIPTS=	honeydarpd

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/sbin
	${INSTALL_MAN_DIR} ${PREFIX}/man/man8
	${CP} ${WRKSRC}/arpd ${WRKSRC}/honeyd-arpd
	${CP} ${WRKSRC}/arpd.8 ${WRKSRC}/honeyd-arpd.8
	${INSTALL_PROGRAM} ${WRKSRC}/honeyd-arpd ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/honeyd-arpd.8 ${PREFIX}/man/man8

.include "../../devel/libevent/buildlink2.mk"
.include "../../net/libdnet/buildlink2.mk"
.include "../../net/libpcap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

