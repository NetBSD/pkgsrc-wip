# $NetBSD: Makefile,v 1.1.1.1 2004/09/06 15:47:19 poppnk Exp $
#

DISTNAME=		tcpspy-1.7
CATEGORIES=		wip
MASTER_SITES=		http://www.mirrors.wiretapped.net/security/network-monitoring/tcpspy/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://freshmeat.net/projects/tcpspy/
COMMENT=		TCP/IP connections logger

USE_BUILDLINK3=		yes

ONLY_FOR_PLATFORM=	Linux-*-* # It uses /proc and some linux-defines

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpspy ${PREFIX}/sbin/tcpspy
	${INSTALL_MAN} ${WRKSRC}/tcpspy.8 ${PREFIX}/man/man8/tcpspy.8

.include "../../mk/bsd.pkg.mk"
