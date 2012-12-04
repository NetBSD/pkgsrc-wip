# $NetBSD: Makefile,v 1.10 2012/12/04 23:25:15 othyro Exp $
#

DISTNAME=	memdump-1.01
CATEGORIES=	sysutils
MASTER_SITES=	http://www.porcupine.org/forensics/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.porcupine.org/forensics/tct.html
COMMENT=	Memory dumper for UNIX-like systems
LICENSE=	postfix-license

USE_TOOLS+=		gmake
BUILD_TARGET=		what
INSTALLATION_DIRS=	${PKGMANDIR}/man1 sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/memdump ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/memdump.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
