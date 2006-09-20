# $NetBSD: Makefile,v 1.1.1.1 2006/09/20 20:28:26 dhowland Exp $
#

PKGNAME=		rainbowcrack-1.2
DISTNAME=		rainbowcrack-1.2-src
CATEGORIES=		security
MASTER_SITES=		http://www.rainbowcrack.com/downloads/
EXTRACT_SUFX=		.zip
DISTFILES=		rainbowcrack-1.2-src.zip \
                        rainbowcrack-1.2-openbsd-diffs.tar.gz

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://www.antsight.com/zsl/rainbowcrack
COMMENT=		Hash cracker

WRKSRC=			${WRKDIR}/rainbowcrack-1.2-src/src

EXTRACT_OPTS_ZIP=	-aqo
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake patch

pre-build:
	${CP} ${WRKDIR}/makefile.openbsd ${WRKSRC}/Makefile
	## ${CP} ${WRKSRC}/makefile.linux ${WRKSRC}/Makefile
	cd ${WRKSRC} && ${PATCH} <${WRKDIR}/Public.cpp.diff

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
