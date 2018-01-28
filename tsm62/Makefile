# $NetBSD: Makefile,v 1.9 2014/01/09 13:42:06 hfath Exp $

DISTNAME=	tsm-6.2.4.0
PKGREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.software.ibm.com/storage/tivoli-storage-management/maintenance/client/v6r2/Linux/LinuxX86/v624/
DISTFILES=	6.2.4.0-TIV-TSMBAC-LinuxX86.tar

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	http://www-306.ibm.com/software/tivoli/products/storage-mgr/
COMMENT=	IBM Tivoli Storage Manager Client

PKG_SYSCONFSUBDIR=	tsm
DOC_DIR=		${DESTDIR}${PREFIX}/share/doc/tsm
EG_DIR=			${DESTDIR}${PREFIX}/share/examples/tsm
CONF_FILES=		${EG_DIR}/dsm.sys.smp ${PKG_SYSCONFDIR}/dsm.sys
CONF_FILES+=		${EG_DIR}/dsm.opt.smp ${PKG_SYSCONFDIR}/dsm.opt

PUBLIC_BINS=		dsmc

NOT_FOR_PLATFORM=	Linux-*-* NetBSD-[0-1]*-*

EMUL_PLATFORMS=		linux-i386 linux-x86_64
EMUL_MODULES.linux=	base

.include "../../mk/bsd.prefs.mk"

WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty

USE_TOOLS+=		rpm2pkg grep sed

RPMFILES=		${WRKDIR}/TIVsm-BA.i386.rpm \
			${WRKDIR}/TIVsm-HSM.i386.rpm \
			${WRKDIR}/TIVsm-API.i386.rpm \
			${WRKDIR}/gskcrypt32-8.0.14.6.linux.x86.rpm \
			${WRKDIR}/gskssl32-8.0.14.6.linux.x86.rpm

EMUL_PKG_FMT=		rpm
RPM2PKG_PREFIX=		${DESTDIR}${PREFIX}
RPM2PKG_SUBPREFIX=	${EMULSUBDIR}
RPM2PKG_STRIP=		0
RPM2PKG_PLIST=		# none generated
RPM2PKG_STAGE=		do-install

PLIST_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
PLIST_SUBST+=		EMULDIR=${EMULDIR}
PLIST_SUBST+=		TSMCLIENTSUBDIR=${TSMCLIENTSUBDIR:Q}

TSM_LOCALE=		${PKG_SYSCONFDIR}/en_US
CHECK_FILES_SKIP+=	${TSM_LOCALE}

TSMCLIENTSUBDIR=	opt/tivoli/tsm/client

MESSAGE_SUBST+=		EMULDIR=${EMULDIR}

.if ${EMUL_PLATFORM} == "linux-x86_64"
RPMFILES+=		${WRKDIR}/TIVsm-API64.i386.rpm \
			${WRKDIR}/gskcrypt64-8.0.14.6.linux.x86_64.rpm \
			${WRKDIR}/gskssl64-8.0.14.6.linux.x86_64.rpm

# Make sure suse pkg version equals the above
DEPENDS+=		suse32_base-[0-9]*:../../emulators/suse121_32_base

EMUL32DIR=		${PREFIX}${_OPSYS_EMULDIR.linux32}
PLIST_SUBST+=		EMUL32DIR=${EMUL32DIR:Q}
MESSAGE_SUBST+=		EMUL32DIR=${EMUL32DIR:Q}
MAKE_DIRS+=		${EMUL32DIR}/etc/ld.so.conf.d

LDCONFIG_ADD_CMD=	${EMULDIR}/sbin/ldconfig ; ${EMUL32DIR}/sbin/ldconfig
LDCONFIG_REMOVE_CMD=	${LDCONFIG_ADD_CMD}
.endif

.include "options.mk"

do-extract:
	cd ${WRKDIR} && ${EXTRACTOR} ${DISTDIR}/${DISTFILES:Q}

post-install:
.if empty(PKG_OPTIONS:Mjava)
	for bb in `${SED} -e '/^[$$]{PLIST\.java}/!d' -e 's/^[$$]{PLIST\.java}//g' ${PLIST_SRC}`; do \
	    ${RM} -f ${DESTDIR}${PREFIX}/$${bb}; \
	done
.endif
	${INSTALL_DATA_DIR} ${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/NOTICES.TXT ${DOC_DIR}
	${INSTALL_DATA_DIR} ${EG_DIR}
	${INSTALL_DATA} ${DESTDIR}${EMULDIR}/${TSMCLIENTSUBDIR}/ba/bin/dsm.*.smp \
		${EG_DIR}
	${INSTALL_DATA} ${FILESDIR}/tsm_daily.sh ${EG_DIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EMULDIR}/etc/ld.so.conf.d
	${INSTALL_DATA} ${FILESDIR}/tsm_ld.so.conf.${MACHINE_ARCH} \
		${DESTDIR}${EMULDIR}/etc/ld.so.conf.d/tsm_ld.so.conf
.if ${EMUL_PLATFORM} == "linux-x86_64"
	${INSTALL_DATA_DIR} ${DESTDIR}${EMUL32DIR}/opt
	${LN} -s /..${EMULDIR}/opt/tivoli/ \
		${DESTDIR}${EMUL32DIR}/opt/tivoli
	${INSTALL_DATA_DIR} ${DESTDIR}${EMUL32DIR}/usr/local/ibm
	${LN} -s /..${EMULDIR}/usr/local/ibm/gsk8/ \
		${DESTDIR}${EMUL32DIR}/usr/local/ibm/gsk8
	${INSTALL_DATA_DIR} ${DESTDIR}${EMUL32DIR}/etc/ld.so.conf.d
	${INSTALL_DATA} ${FILESDIR}/tsm_ld.so.conf.i386 \
		${DESTDIR}${EMUL32DIR}/etc/ld.so.conf.d/tsm_ld.so.conf
.endif
	${LN} -s /..${PKG_SYSCONFDIR}/dsm.sys \
		${DESTDIR}${EMULDIR}/${TSMCLIENTSUBDIR}/ba/bin/
	${LN} -s /..${PKG_SYSCONFDIR}/dsm.opt \
		${DESTDIR}${EMULDIR}/${TSMCLIENTSUBDIR}/ba/bin/
	${LN} -s ../../lang/EN_US \
		${DESTDIR}${EMULDIR}/${TSMCLIENTSUBDIR}/ba/bin/
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin
.for bb in ${PUBLIC_BINS}
	${LN} -s ${EMULDIR}/${TSMCLIENTSUBDIR}/ba/bin/${bb} \
		${DESTDIR}${PREFIX}/bin/${bb}
.endfor

.include "../../mk/bsd.pkg.mk"
