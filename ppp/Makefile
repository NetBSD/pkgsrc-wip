# $NetBSD: Makefile,v 1.5 2003/09/30 00:44:24 jeremy-c-reed Exp $

DISTNAME=	ppp-2.4.1
CATEGORIES=	net
MASTER_SITES=	http://ftp.samba.org/ftp/ppp/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.samba.org/ppp/
COMMENT=	Point-to-Point Protocol (PPP) over serial lines

HAS_CONFIGURE=	yes
USE_GMAKE=	yes

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
