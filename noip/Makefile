# $NetBSD: Makefile,v 1.5 2006/08/14 16:31:14 dhowland Exp $

DISTNAME=	noip-duc-linux
PKGNAME=	noip-2.1.3
CATEGORIES=	net
MASTER_SITES=	http://www.no-ip.com/client/linux/

MAINTAINER=	dhowland@users.sourceforge.net
HOMEPAGE=	http://www.no-ip.com/
COMMENT=	Dynamic DNS update client from no-ip.com

RCD_SCRIPTS=	noip

.include "../../mk/bsd.prefs.mk"

post-extract:
	${RM} ${WRKDIR}/${PKGNAME}/Makefile
	${CP} ${FILESDIR}/makefile.noip ${WRKDIR}/${PKGNAME}/Makefile
	${MV} ${WRKDIR}/${PKGNAME} ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/noip2 ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/noip
	${INSTALL_MAN} ${WRKSRC}/README.FIRST ${PREFIX}/share/doc/noip
	${INSTALL_MAN} ${WRKSRC}/COPYING ${PREFIX}/share/doc/noip

.include "../../mk/bsd.pkg.mk"
