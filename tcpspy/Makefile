# $NetBSD: Makefile,v 1.4 2006/04/20 13:36:44 cheusov Exp $
#

DISTNAME=		tcpspy-1.7
CATEGORIES=		net
MASTER_SITES=		http://www.mirrors.wiretapped.net/security/network-monitoring/tcpspy/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://freshmeat.net/projects/tcpspy/
COMMENT=		TCP/IP connections logger


ONLY_FOR_PLATFORM=	Linux-*-* # It uses /proc and some linux-defines

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpspy ${PREFIX}/sbin/tcpspy
	${INSTALL_MAN} ${WRKSRC}/tcpspy.8 ${PREFIX}/${PKGMANDIR}/man8/tcpspy.8

.include "../../mk/bsd.pkg.mk"
