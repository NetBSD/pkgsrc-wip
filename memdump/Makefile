# $NetBSD: Makefile,v 1.5 2008/03/09 01:56:02 dhowland Exp $
#

DISTNAME=		memdump-1.01
CATEGORIES=		sysutils
MASTER_SITES=		http://www.porcupine.org/forensics/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.porcupine.org/forensics/tct.html
COMMENT=		Memory dumper for UNIX-like systems

USE_TOOLS+=		gmake
BUILD_TARGET=		what
INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/memdump ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/memdump.1 ${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
