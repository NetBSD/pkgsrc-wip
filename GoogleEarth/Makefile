# $NetBSD: Makefile,v 1.21 2015/03/12 21:45:08 tnn2 Exp $

DISTNAME=		google-earth-stable_${GE_VERSION}_amd64.deb
PKGNAME=		GoogleEarth-${GE_VERSION}
CATEGORIES=		geography x11
MASTER_SITES=		-http://dl.google.com/earth/client/current/google-earth-stable_current_amd64.deb
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

GE_VERSION=		7.1.8.3036
NO_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
EXTRACT_CMD=		ar x "$$extract_file"

INSTALLATION_DIRS=	bin share

USE_TOOLS+=		pax xzcat tar

post-extract:
	cd ${WRKDIR} && mkdir -p ${WRKSRC} && ${XZCAT} data.tar.xz | ${TAR} -C ${WRKSRC} -xf -

do-build:
	printf '#! /bin/sh\nLD_LIBRARY_PATH=${PREFIX}/share/google/earth/free exec ${PREFIX}/share/google/earth/free/googleearth-bin "$$@"\n' > \
	${WRKDIR}/google-earth

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/google-earth ${DESTDIR}${PREFIX}/bin/google-earth
	cd ${WRKSRC}/opt && pax -rw google ${DESTDIR}${PREFIX}/share

.include "../../mk/bsd.pkg.mk"
