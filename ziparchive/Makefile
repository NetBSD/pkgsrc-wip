# $NetBSD: Makefile,v 1.2 2012/10/07 20:11:11 asau Exp $
#

DISTNAME=	ziparchive
PKGNAME=	ziparchive-4.1.0
CATEGORIES=	archivers
MASTER_SITES=	http://www.artpol-software.com/Downloads/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.artpol-software.com/Download.aspx
COMMENT=	Library for ZIP compression and decompression
LICENSE=	gnu-gpl-v2

DIST_SUBDIR=		ziparchive-4.1.0

WRKSRC=		${WRKDIR} # More than one possibility -- please check manually.
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

BUILD_DIRS=	ZipArchive
BUILD_TARGET=	# blank

INSTALL_MAKE_FLAGS=	prefix=${DESTDIR}${PREFIX}

pre-configure:
	${CP} ${WRKSRC}/_projects/Linux/Makefile ${WRKSRC}/ZipArchive/

.include "../../mk/bsd.pkg.mk"
