# $NetBSD: Makefile,v 1.1.1.1 2003/09/02 06:11:09 xtraeme Exp $
# $FreeBSD: ports/net/noip/Makefile,v 1.1 2002/06/25 09:32:28 ijliao Exp $

DISTNAME=	noip_updater_v1.6
PKGNAME=	noip-1.6
CATEGORIES=	net
MASTER_SITES=	http://www.no-ip.com/client/linux/

MAINTAINER=	david@netbsd-fr.org
COMMENT=	Dynamic DNS update client from no-ip.com

ALL_TARGET=	noip
PKG_GROUPS=	noip
PKG_USERS=	noip:noip

post-build:
	${CP} ${FILESDIR}/noip.sh ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/noip ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/noip.sh ${PREFIX}/etc/rc.d/noip

	${INSTALL_DATA_DIR} ${PREFIX}/share/noip
	${INSTALL_DATA_DIR} ${PREFIX}/share/noip/doc
	${INSTALL_MAN} ${WRKSRC}/README.FIRST ${PREFIX}/share/noip/doc
	${INSTALL_MAN} ${WRKSRC}/COPYING ${PREFIX}/share/noip/doc
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/noip
	${INSTALL_MAN} ${WRKSRC}/no-ip.conf.sample	\
		${PREFIX}/share/examples/noip
	${INSTALL_SCRIPT} ${WRKSRC}/noip.sh ${PREFIX}/share/examples/noip
	${CP} ${PREFIX}/share/examples/noip/no-ip.conf.sample	\
		${PREFIX}/etc/no-ip.conf
	${CHMOD} 0600 ${PREFIX}/etc/no-ip.conf
	${CHOWN} noip:noip ${PREFIX}/etc/no-ip.conf

USE_PKGINSTALL=	YES

.include "../../mk/bsd.pkg.mk"
