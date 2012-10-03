# $NetBSD: Makefile,v 1.9 2012/10/03 17:52:04 asau Exp $

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

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/noip2 ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/noip
	${INSTALL_MAN} ${WRKSRC}/README.FIRST ${DESTDIR}${PREFIX}/share/doc/noip
	${INSTALL_MAN} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/noip

.include "../../mk/bsd.pkg.mk"
