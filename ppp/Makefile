# $NetBSD: Makefile,v 1.7 2004/01/27 03:05:20 minskim Exp $

DISTNAME=	ppp-2.4.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.samba.org/pub/ppp/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.samba.org/ppp/
COMMENT=	Point-to-Point Protocol (PPP) over serial lines

HAS_CONFIGURE=	yes
USE_GNU_TOOLS+=	make

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ppp
	${INSTALL_DATA} ${WRKSRC}/FAQ ${PREFIX}/share/doc/ppp
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ppp
	${INSTALL_DATA} ${WRKSRC}/SETUP ${PREFIX}/share/doc/ppp
	${INSTALL_DATA_DIR} ${PREFIX}/share/ppp
	${INSTALL_DATA} ${WRKSRC}/etc.ppp/chap-secrets ${PREFIX}/share/ppp
	${INSTALL_DATA} ${WRKSRC}/etc.ppp/options ${PREFIX}/share/ppp
	${INSTALL_DATA} ${WRKSRC}/etc.ppp/pap-secrets ${PREFIX}/share/ppp

.include "../../mk/bsd.pkg.mk"
