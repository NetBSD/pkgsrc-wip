# $NetBSD: Makefile,v 1.3 2005/11/02 18:00:22 thomasklausner Exp $
#

DISTNAME=		memdump-1.01
CATEGORIES=		sysutils
MASTER_SITES=		http://www.porcupine.org/forensics/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.porcupine.org/forensics/tct.html
COMMENT=		Memory dumper for UNIX-like systems

USE_TOOLS+=		gmake
BUILD_TARGET=		what

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/memdump ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/memdump.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
