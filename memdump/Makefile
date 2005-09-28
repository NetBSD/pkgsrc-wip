# $NetBSD: Makefile,v 1.2 2005/09/28 07:38:35 rillig Exp $
#

DISTNAME=		memdump-1.01
CATEGORIES=		wip sysutils
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
