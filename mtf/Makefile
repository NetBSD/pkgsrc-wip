# $NetBSD: Makefile,v 1.8 2009/07/28 15:23:56 jihbed Exp $

DISTNAME=	mtf-0.2.1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/backup/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.laytongraphics.com/mtf/
COMMENT=	Unix reader for the Microsoft Tape Format used by NT Backup
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=	# empty
MTF_DOCSDIR=	${PREFIX}/share/doc/mtf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mtf ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${MTF_DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${MTF_DOCSDIR}

.include "../../mk/bsd.pkg.mk"
