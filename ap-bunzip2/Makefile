# $NetBSD: Makefile,v 1.8 2005/04/11 21:09:45 tvierling Exp $
#

DISTNAME=	mod_bunzip2
PKGNAME=	${DISTNAME:S/mod_/ap-/}-0.1
WRKSRC=         ${WRKDIR}/mod_bunzip2-2
CATEGORIES=	www
MASTER_SITES=	http://www.oldach.net/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.oldach.net/
COMMENT=	Apache module for server-side decompression of bzip2 files


APACHE_MODULE_NAME=     ${DISTNAME:C|-.*||}.so
APACHE_MODULE_SRC=      ${DISTNAME:C|-.*||}.c

DOCDIR=		${PREFIX}/share/doc/${PKGNAME}

pre-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
