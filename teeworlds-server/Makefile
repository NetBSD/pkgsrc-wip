# $NetBSD: Makefile,v 1.2 2010/06/29 14:07:26 hftmarkand Exp $

.include "../teeworlds/Makefile.common"

PKGNAME=	teeworlds-server-${TEEWORLDS_VERSION}
CONFLICTS+=	teeworlds-[0-9]*
CONFLICTS+=	teeworlds-client-[0-9]*

# Use the same settings.
DISTINFO_FILE=	${.CURDIR}/../teeworlds/distinfo
PATCHDIR=	${.CURDIR}/../teeworlds/patches
DESCR_SRC=	${.CURDIR}/../teeworlds/DESCR

# Remove X libs because we don't need them.
SUBST_STAGE.default-bam=	pre-build
SUBST_MESSAGE.default-bam=	Fixing default bam for python
SUBST_FILES.default-bam=	${TEEWORLDS_WRKSRC}/default.bam
SUBST_SED.default-bam=		-e 's,@PYTHONBIN@,${PYTHONBIN},; s,@CFLAGS@,${CFLAGS},; s,@X11BASE@,,g'

# We want server only target.
BAM_TARGET=	server_release

do-build:
	cd ${BAM_WRKSRC} && sh make_unix.sh
	cd ${TEEWORLDS_WRKSRC} && ${BAM_WRKSRC}/src/bam -v ${BAM_TARGET}

do-install:
	${INSTALL_PROGRAM} ${TEEWORLDS_WRKSRC}/teeworlds_srv ${DESTDIR}${PREFIX}/bin

	cd ${TEEWORLDS_WRKSRC}/data/maps && ${PAX} -rw . ${DESTDIR}${DATADIR}/maps

.include "../../mk/bsd.pkg.mk"
