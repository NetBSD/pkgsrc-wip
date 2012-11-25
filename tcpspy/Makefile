# $NetBSD: Makefile,v 1.7 2012/11/25 23:32:31 othyro Exp $
#

DISTNAME=		tcpspy-1.7
CATEGORIES=		net
MASTER_SITES=		http://www.mirrors.wiretapped.net/security/network-monitoring/tcpspy/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://freshmeat.net/projects/tcpspy/
COMMENT=		TCP/IP connections logger

ONLY_FOR_PLATFORM=	Linux-*-* # It uses /proc and some linux-defines

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpspy ${DESTDIR}${PREFIX}/sbin/tcpspy
	${INSTALL_MAN} ${WRKSRC}/tcpspy.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/tcpspy.8

.include "../../mk/bsd.pkg.mk"
