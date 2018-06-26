# $NetBSD$

DISTNAME=	tsm-6.2.4.0
PKGREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.software.ibm.com/storage/tivoli-storage-management/maintenance/client/v6r2/Linux/LinuxX86/v624/
DISTFILES=	6.2.4.0-TIV-TSMBAC-LinuxX86.tar

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	https://www.ibm.com/us-en/marketplace/data-protection-and-recovery
COMMENT=	IBM Tivoli Storage Manager Client

PKG_SYSCONFSUBDIR=	tsm
DOC_DIR=		share/doc/tsm
EG_DIR=			share/examples/tsm
CONF_FILES=		${PREFIX}/${EG_DIR}/dsm.sys.smp ${PKG_SYSCONFDIR}/dsm.sys
CONF_FILES+=		${PREFIX}/${EG_DIR}/dsm.opt.smp ${PKG_SYSCONFDIR}/dsm.opt

PUBLIC_BINS=		dsmc

NOT_FOR_PLATFORM=	Linux-*-* NetBSD-[0-1]*-*

EMUL_PLATFORMS=		linux-i386 linux-x86_64
EMUL_MODULES.linux=	base
RUN_LDCONFIG=		yes

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

EMUL32DIR=		${_OPSYS_EMULDIR.linux32}
EMUL32SUBDIR=		${_OPSYS_EMULDIR.linux32:S/^\///1}

PLIST_SUBST+=		EMUL32DIR=${EMUL32DIR:Q}
MESSAGE_SUBST+=		EMUL32DIR=${EMUL32DIR:Q}

INSTALLATION_DIRS+=	${EMUL32SUBDIR}/opt
INSTALLATION_DIRS+=	${EMUL32SUBDIR}/etc/ld.so.conf.d
INSTALLATION_DIRS+=	${EMUL32SUBDIR}/usr/local/ibm

LDCONFIG_ADD_CMD=	${EMULDIR}/sbin/ldconfig ; ${EMUL32DIR}/sbin/ldconfig
LDCONFIG_REMOVE_CMD=	${LDCONFIG_ADD_CMD}
.endif

INSTALLATION_DIRS+=	bin ${EMULSUBDIR}/etc/ld.so.conf.d ${DOC_DIR} ${EG_DIR}

.include "options.mk"

do-extract:
	cd ${WRKDIR} && ${EXTRACTOR} ${DISTDIR}/${DISTFILES:Q}

post-install:
.if empty(PKG_OPTIONS:Mjava)
	for bb in `${SED} -e '/^[$$]{PLIST\\.java}/!d' -e 's/^[$$]{PLIST\\.java}//g' ${PLIST_SRC}`; do \
	    ${RM} -f ${DESTDIR}${PREFIX}/$${bb}; \
	done
.endif
	${INSTALL_DATA} ${WRKSRC}/NOTICES.TXT ${DESTDIR}${PREFIX}/${DOC_DIR}
	${INSTALL_DATA} ${DESTDIR}${EMULDIR}/${TSMCLIENTSUBDIR}/ba/bin/dsm.*.smp \
		${DESTDIR}${PREFIX}/${EG_DIR}
	${INSTALL_DATA} ${FILESDIR}/tsm_daily.sh ${DESTDIR}${PREFIX}/${EG_DIR}
	${INSTALL_DATA} ${FILESDIR}/tsm_ld.so.conf.${MACHINE_ARCH} \
		${DESTDIR}${EMULDIR}/etc/ld.so.conf.d/tsm_ld.so.conf
.if ${EMUL_PLATFORM} == "linux-x86_64"
	${LN} -s /..${EMULDIR}/opt/tivoli/ \
		${DESTDIR}${PREFIX}${EMUL32DIR}/opt/tivoli
	${LN} -s /..${EMULDIR}/usr/local/ibm/gsk8/ \
		${DESTDIR}${PREFIX}${EMUL32DIR}/usr/local/ibm/gsk8
	${INSTALL_DATA} ${FILESDIR}/tsm_ld.so.conf.i386 \
		${DESTDIR}${PREFIX}${EMUL32DIR}/etc/ld.so.conf.d/tsm_ld.so.conf
.endif
	${LN} -s /..${PKG_SYSCONFDIR}/dsm.sys \
		${DESTDIR}${EMULDIR}/${TSMCLIENTSUBDIR}/ba/bin/
	${LN} -s /..${PKG_SYSCONFDIR}/dsm.opt \
		${DESTDIR}${EMULDIR}/${TSMCLIENTSUBDIR}/ba/bin/
	${LN} -s ../../lang/EN_US \
		${DESTDIR}${EMULDIR}/${TSMCLIENTSUBDIR}/ba/bin/
.for bb in ${PUBLIC_BINS}
	${LN} -s ../${EMULSUBDIR}/${TSMCLIENTSUBDIR}/ba/bin/${bb} \
		${DESTDIR}${PREFIX}/bin/${bb}
.endfor

.include "../../mk/bsd.pkg.mk"
