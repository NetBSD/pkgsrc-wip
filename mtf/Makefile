# $NetBSD: Makefile,v 1.9 2012/10/03 14:45:48 asau Exp $

DISTNAME=	mtf-0.2.1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/backup/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.laytongraphics.com/mtf/
COMMENT=	Unix reader for the Microsoft Tape Format used by NT Backup
LICENSE=	gnu-gpl-v2

BUILD_TARGET=	# empty
MTF_DOCSDIR=	${PREFIX}/share/doc/mtf

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mtf ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${MTF_DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${MTF_DOCSDIR}

.include "../../mk/bsd.pkg.mk"
