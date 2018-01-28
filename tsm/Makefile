# $NetBSD: Makefile,v 1.18 2012/11/20 11:44:13 hfath Exp $

DISTNAME=	tsm-5.2.5
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.software.ibm.com/storage/tivoli-storage-management/maintenance/client/v5r2/Linux/Linux86/v525/
DISTFILES=	TSM525C_LINUX86.tar

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	http://www-306.ibm.com/software/tivoli/products/storage-mgr/
COMMENT=	IBM Tivoli Storage Manager Client

PKG_SYSCONFSUBDIR=	tsm
EG_DIR=			${PREFIX}/share/examples/tsm
CONF_FILES=		${DESTDIR}${EG_DIR}/dsm.sys.smp \
			${PKG_SYSCONFDIR}/dsm.sys
CONF_FILES+=		${DESTDIR}${EG_DIR}/dsm.opt.smp \
			${PKG_SYSCONFDIR}/dsm.opt
CONF_FILES=		${DESTDIR}${EG_DIR}/tsm_ld_so.conf \
			${EMULDIR}/etc/ld.so.conf.d/tsm.conf

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	compat x11
SUSE_VERSION_REQD=	7.3

# Stronger than "prefer" - tsm 5.2.5 does not work with newer suse_*
SUSE_PREFER=		10.0

NOT_FOR_PLATFORM=	Linux-*-* NetBSD-[0-1]*-*

WRKSRC=			${WRKDIR}
TEMP?=			${WRKSRC}
BUILD_DIRS=		# empty

USE_TOOLS+=		rpm2pkg
EMUL_PKG_FMT=		rpm
RPM2PKG_PREFIX=		${DESTDIR}${PREFIX}
RPM2PKG_SUBPREFIX=	${EMULSUBDIR}
RPM2PKG_STRIP=		0
RPM2PKG_STAGE=		do-install
RPMFILES=		${WRKSRC}/TIVsm-API.i386.rpm \
			${WRKSRC}/TIVsm-BA.i386.rpm

TSMCLIENTSUBDIR=	opt/tivoli/tsm/client

PLIST_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
PLIST_SUBST+=		TSMCLIENTSUBDIR=${TSMCLIENTSUBDIR:Q}
PLIST_SUBST+=		EMULDIR=${EMULDIR}

MESSAGE_SUBST+=		TSMCLIENTSUBDIR=${TSMCLIENTSUBDIR:Q}
MESSAGE_SUBST+=		EMULDIR=${EMULDIR}

MAKE_DIRS+=		${EMULDIR}/etc/ld.so.conf.d

post-patch:
	${SED} -e "s,@TSMCLIENTSUBDIR@,${TSMCLIENTSUBDIR},g" \
		${FILESDIR}/tsm_ld_so.conf > ${WRKDIR}/tsm_ld_so.conf
do-extract:
	cd ${WRKDIR} && ${EXTRACTOR} ${DISTDIR}/${DISTFILES:Q}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EG_DIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EMULDIR}/etc/ld.so.conf.d
	${INSTALL_DATA} \
		${DESTDIR}${EMULDIR}/${TSMCLIENTSUBDIR}/ba/bin/dsm.*.smp \
		${DESTDIR}${EG_DIR}
	${INSTALL_DATA} ${FILESDIR}/tsm_daily.sh ${DESTDIR}${EG_DIR}
	${INSTALL_DATA} ${WRKDIR}/tsm_ld_so.conf ${DESTDIR}${EG_DIR}

.include "../../mk/bsd.pkg.mk"
