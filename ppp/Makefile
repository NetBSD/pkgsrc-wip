# $NetBSD: Makefile,v 1.10 2012/10/05 13:52:03 asau Exp $

DISTNAME=	ppp-2.4.1
CATEGORIES=	net
#MASTER_SITES=	ftp://ftp.samba.org/pub/ppp/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.samba.org/ppp/
COMMENT=	Point-to-Point Protocol (PPP) over serial lines

ONLY_FOR_PLATFORM=	Linux-*-* SunOS-5*-*


HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake

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
