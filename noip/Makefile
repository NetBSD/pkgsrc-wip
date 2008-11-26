# $NetBSD: Makefile,v 1.8 2008/11/26 20:54:55 gschwarz Exp $

DISTNAME=	noip-duc-linux
PKGNAME=	noip-2.1.9
CATEGORIES=	net
MASTER_SITES=	http://www.no-ip.com/client/linux/

MAINTAINER=	dhowland@users.sourceforge.net
HOMEPAGE=	http://www.no-ip.com/
COMMENT=	Dynamic DNS update client from no-ip.com

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}-1
RCD_SCRIPTS=	noip

.include "../../mk/bsd.prefs.mk"

post-extract:
	${RM} ${WRKSRC}/Makefile
	${CP} ${FILESDIR}/makefile.noip ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/noip2 ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/noip
	${INSTALL_MAN} ${WRKSRC}/README.FIRST ${PREFIX}/share/doc/noip
	${INSTALL_MAN} ${WRKSRC}/COPYING ${PREFIX}/share/doc/noip

.include "../../mk/bsd.pkg.mk"
