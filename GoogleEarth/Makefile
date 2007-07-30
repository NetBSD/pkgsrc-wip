# $NetBSD: Makefile,v 1.5 2007/07/30 15:49:10 jlamwww Exp $

DISTNAME=		GoogleEarthLinux.bin
PKGNAME=		GoogleEarth-${GE_VERSION}
CATEGORIES=		geography x11
MASTER_SITES=		http://dl.google.com/earth/client/current/
EXTRACT_SUFX=

MAINTAINER=		tnn@NetBSD.org
HOMEPAGE=		http://earth.google.com/
COMMENT=		Interactive browser for satellite imagery and maps

LICENSE=		google-earth-license
LICENSE_FILE=		${FILESDIR}/google-earth-license
RESTRICTED=		No redistribution allowed
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

# XXX still complains about missing font
DEPENDS+=	vera-ttf>=1.10:../../fonts/vera-ttf
DEPENDS+=	suse_fontconfig>=10.0nb2:../../emulators/suse100_fontconfig
DEPENDS+=	suse_glx>=10.0nb2:../../emulators/suse100_glx

EMUL_PLATFORMS=		linix-i386
NOT_FOR_PLATFORM=	NetBSD-[0-2]*-*

GE_VERSION=		4.1.7076.4458
NO_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/GoogleEarthLinuxPlus-${GE_VERSION}-installer
DIST_SUBDIR=		${PKGNAME_NOREV}
EXTRACT_CMD=		${SH} "$$extract_file" --noexec --keep

do-build:
	cd ${WRKSRC} && ${MKDIR} GoogleEarth && cd GoogleEarth && \
	${PAX} -r -f ../googleearth-linux-x86.tar && \
	${PAX} -r -f ../googleearth-data.tar && \
	${CP} ../*.xpm ../*.png ../bin/googleearth . && \
	${FIND} . -type f | ${XARGS} ${CHMOD} -x && \
	${CHMOD} +x googleearth googleearth-bin *.so*
	printf '#! /bin/sh\nexec ${PREFIX}/GoogleEarth/googleearth "$$@"\n' > \
	${WRKDIR}/googleearth

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/googleearth ${PREFIX}/bin/googleearth
	cd ${WRKSRC} && ${PAX} -rw GoogleEarth ${PREFIX}

.include "../../mk/bsd.pkg.mk"
