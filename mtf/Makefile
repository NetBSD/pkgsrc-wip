# $NetBSD: Makefile,v 1.5 2005/03/24 21:13:29 thomasklausner Exp $

DISTNAME=	mtf-0.2.1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/backup/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.layton-graphics.com/mtf/
COMMENT=	Unix reader for the Microsoft Tape Format used by NT Backup

BUILD_TARGET=	# empty
MTF_DOCSDIR=	${PREFIX}/share/doc/mtf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mtf ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${MTF_DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${MTF_DOCSDIR}

.include "../../mk/bsd.pkg.mk"
