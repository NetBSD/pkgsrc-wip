# $NetBSD: Makefile,v 1.7 2012/12/03 13:53:00 othyro Exp $
#

DISTNAME=	bmap-1.0.17
CATEGORIES=	sysutils
MASTER_SITES=	http://packetstorm.tacticalflex.com/linux/security/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://packetstormsecurity.org/files/17642/bmap-1.0.17.tar.gz.html
COMMENT=	Forensic tool to perform low-level operations on ext2 filesystems
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man2 share/doc/bmap
ONLY_FOR_PLATFORM=	Linux-*-* # XXX Needs linux/fs.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bmap ${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/slacker ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/man2/libbmap.2 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man2/
	${INSTALL_DATA} ${WRKSRC}/bmap.sgml ${DESTDIR}${PREFIX}/share/doc/bmap/
	${INSTALL_DATA} ${WRKSRC}/bmap-invoke.sgml ${DESTDIR}${PREFIX}/share/doc/bmap/
	${INSTALL_DATA} ${WRKSRC}/slacker-invoke.sgml ${DESTDIR}${PREFIX}/share/doc/bmap/

.include "../../mk/bsd.pkg.mk"
