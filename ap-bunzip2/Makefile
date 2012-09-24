# $NetBSD: Makefile,v 1.12 2012/09/24 16:56:35 asau Exp $
#

DISTNAME=	mod_bunzip2
PKGNAME=	${DISTNAME:S/mod_/ap-/}-0.1
WRKSRC=		${WRKDIR}/mod_bunzip2-2
CATEGORIES=	www
MASTER_SITES=	http://oldach.net/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://oldach.net/
COMMENT=	Apache module for server-side decompression of bzip2 files

PKG_DESTDIR_SUPPORT=	none

APACHE_MODULE_NAME=	${DISTNAME:C|-.*||}.so
APACHE_MODULE_SRC=	${DISTNAME:C|-.*||}.c

DOCDIR=		${PREFIX}/share/doc/${PKGNAME}

pre-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
