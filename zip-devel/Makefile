# $NetBSD: Makefile,v 1.64 2015/08/28 08:17:38 richard Exp $

DISTNAME=	zip31d
PKGNAME=	zip-3.1pre4
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.info-zip.org/pub/infozip/beta/ \
		ftp://ftp.info-zip.org/pub/infozip/crypt/
EXTRACT_SUFX=	.zip
DISTFILES=	${DISTNAME}.zip iz_aes_wg15.zip

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.info-zip.org/Zip.html
COMMENT=	Create/update ZIP files compatible with pkzip
LICENSE=	info-zip

MAKE_FILE=	unix/Makefile

MAKE_FLAGS+=	LOCAL_ZIP=${CFLAGS:Q}
MAKE_FLAGS+=	LFLAGS1=${_STRIPFLAG_CC:Q}
MAKE_FLAGS+=	-DUNICODE_SUPPORT

BUILD_TARGET=	generic

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-extract:
	${MV} ${WRKDIR}/aes_wg ${WRKSRC}

do-install:
	cd ${WRKSRC} && \
	    ${INSTALL_PROGRAM} zip zipnote zipsplit zipcloak ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/man/man1 && \
	    ${INSTALL_MAN} *.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
