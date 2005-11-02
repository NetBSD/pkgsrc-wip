# $NetBSD: Makefile,v 1.2 2005/11/02 18:00:01 thomasklausner Exp $
#

DISTNAME=		bmap-1.0.17
CATEGORIES=		sysutils
MASTER_SITES=		http://packetstorm.linuxsecurity.com/linux/security/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://packetstorm.linuxsecurity.com/linux/security/
COMMENT=			Forensic tool to perform low-level operations on ext2 filesystems

USE_TOOLS+= gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bmap ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/slacker ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/man2/libbmap.2 ${PREFIX}/man/man2/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bmap
	${INSTALL_DATA} ${WRKSRC}/bmap.sgml ${PREFIX}/share/doc/bmap/
	${INSTALL_DATA} ${WRKSRC}/bmap-invoke.sgml ${PREFIX}/share/doc/bmap/
	${INSTALL_DATA} ${WRKSRC}/slacker-invoke.sgml ${PREFIX}/share/doc/bmap/

.include "../../mk/bsd.pkg.mk"
