# $NetBSD: Makefile,v 1.5 2012/09/24 17:14:36 asau Exp $
#

DISTNAME=		bmap-1.0.17
CATEGORIES=		sysutils
MASTER_SITES=		http://packetstorm.linuxsecurity.com/linux/security/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://packetstorm.linuxsecurity.com/linux/security/
COMMENT=			Forensic tool to perform low-level operations on ext2 filesystems

USE_TOOLS+= gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bmap ${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/slacker ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/man2/libbmap.2 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man2/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/bmap
	${INSTALL_DATA} ${WRKSRC}/bmap.sgml ${DESTDIR}${PREFIX}/share/doc/bmap/
	${INSTALL_DATA} ${WRKSRC}/bmap-invoke.sgml ${DESTDIR}${PREFIX}/share/doc/bmap/
	${INSTALL_DATA} ${WRKSRC}/slacker-invoke.sgml ${DESTDIR}${PREFIX}/share/doc/bmap/

.include "../../mk/bsd.pkg.mk"
