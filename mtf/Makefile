# $NetBSD: Makefile,v 1.1.1.1 2003/04/20 15:11:22 cjep Exp $
# FreeBSD Id: ports/archivers/mtf/Makefile,v 1.1 2002/06/26 06:33:35 ijliao Exp

DISTNAME=	mtf-0.2.1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/backup/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://layton-graphics.com/mtf/
COMMENT=	Unix reader for the Microsoft Tape Format used by NT Backup

ALL_TARGET=	# empty
MTF_DOCSDIR=	${PREFIX}/share/doc/mtf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mtf ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${MTF_DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${MTF_DOCSDIR}

.include "../../mk/bsd.pkg.mk"
