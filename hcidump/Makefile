# $NetBSD: Makefile,v 1.3 2005/11/14 23:43:28 plunky Exp $

DISTNAME=	hcidump-1.5.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.geocities.com/m_evmenkin/

MAINTAINER=	plunky@rya-online.net
COMMENT=	Bluetooth traffic dumper, similar to tcpdump

ONLY_FOR_PLATFORM=	NetBSD-*-*

WRKSRC=		${WRKDIR}/hcidump

INSTALLATION_DIRS=	man/man1

post-patch:
	${MKDIR} ${WRKSRC}/bluetooth
	${CP} files/bluetooth.h ${WRKSRC}/bluetooth
	${CP} files/hci.h ${WRKSRC}/bluetooth
	${CP} files/l2cap.h ${WRKSRC}/bluetooth

.include "../../mk/bsd.pkg.mk"
