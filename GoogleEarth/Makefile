# $NetBSD: Makefile,v 1.19 2015/03/02 19:59:26 tnn2 Exp $

DISTNAME=		google-earth-stable_current_amd64.deb
PKGNAME=		GoogleEarth-${GE_VERSION}
CATEGORIES=		geography x11
MASTER_SITES=		http://dl.google.com/earth/client/current/
EXTRACT_SUFX=

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://earth.google.com/
COMMENT=		Interactive browser for satellite imagery and maps
LICENSE=		google-earth-license

LICENSE_FILE=		${FILESDIR}/google-earth-license
RESTRICTED=		No redistribution allowed
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

DEPENDS+=		vera-ttf>=1.10:../../fonts/vera-ttf

EMUL_PLATFORMS=		linux-x86_64
EMUL_MODULES.linux=	fontconfig glx gstreamer gtk2 lsb qt4 webp xslt

ONLY_FOR_PLATFORM=	NetBSD-[0-9]*-x86_64 Linux-[0-9]*-x86_64

GE_VERSION=		7.1.2.204
NO_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
DIST_SUBDIR=		${PKGNAME_NOREV}
EXTRACT_CMD=		ar x "$$extract_file"

INSTALLATION_DIRS=	bin share

USE_TOOLS+=		pax lzcat tar

post-extract:
	cd ${WRKDIR} && mkdir -p ${WRKSRC} && ${LZCAT} data.tar.lzma | ${TAR} -C ${WRKSRC} -xf -

do-build:
#	cd ${WRKSRC} && ${MKDIR} GoogleEarth && cd GoogleEarth && \
#	pax -r -f ../googleearth-linux-x86.tar && \
#	pax -r -f ../googleearth-data.tar && \
#	${CP} ../*.xpm ../*.png ../bin/googleearth . && \
#	${FIND} . -type f | ${XARGS} ${CHMOD} -x && \
#	${CHMOD} +x googleearth googleearth-bin *.so*
	printf '#! /bin/sh\nLD_LIBRARY_PATH=${PREFIX}/share/google/earth/free exec ${PREFIX}/share/google/earth/free/googleearth-bin "$$@"\n' > \
	${WRKDIR}/google-earth

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/google-earth ${DESTDIR}${PREFIX}/bin/google-earth
	cd ${WRKSRC}/opt && pax -rw google ${DESTDIR}${PREFIX}/share

.include "../../mk/bsd.pkg.mk"
