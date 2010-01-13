# $NetBSD: Makefile,v 1.15 2010/01/13 14:55:06 hfath Exp $

DISTNAME=	tsm-5.2.5
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.software.ibm.com/storage/tivoli-storage-management/maintenance/client/v5r2/Linux/Linux86/v525/
DISTFILES=	TSM525C_LINUX86.tar

MAINTAINER=	hf@spg.tu-darmstadt.de
HOMEPAGE=	http://www-306.ibm.com/software/tivoli/products/storage-mgr/
COMMENT=	IBM Tivoli Storage Manager Client

PKG_SYSCONFSUBDIR=	tsm
EG_DIR=			${DESTDIR}${PREFIX}/share/examples/tsm
CONF_FILES=		${EG_DIR}/dsm.sys.smp ${PKG_SYSCONFDIR}/dsm.sys \
			${EG_DIR}/dsm.opt.smp ${PKG_SYSCONFDIR}/dsm.opt

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	compat x11
SUSE_VERSION_REQD=	7.3

NOT_FOR_PLATFORM=	Linux-*-* NetBSD-[0-1]*-*

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}
TEMP?=			${WRKSRC}
BUILD_DIRS=		# empty

USE_TOOLS+=		rpm2pkg
EMUL_PKG_FMT=		rpm
RPM2PKG_PREFIX=		${DESTDIR}${PREFIX}
RPM2PKG_SUBPREFIX=	${EMULSUBDIR}
RPM2PKG_STRIP=		0
RPM2PKG_STAGE=		do-install
RPMFILES=		${WRKSRC}/*.rpm

PLIST_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}
PLIST_SUBST+=		EMULDIR=${EMULDIR:Q}
PLIST_SUBST+=		TSMCLIENTSUBDIR=${TSMCLIENTSUBDIR:Q}

TSM_LOCALE=		${PKG_SYSCONFDIR}/en_US
CHECK_FILES_SKIP+=	${TSM_LOCALE}

TSMCLIENTSUBDIR=	opt/tivoli/tsm/client

MESSAGE_SUBST+=		EMULDIR=${EMULDIR:Q}

do-extract:
	cd ${WRKDIR} && ${EXTRACTOR} ${DISTDIR}/${DISTFILES:Q}

post-install:
	if ! ${GREP} -q "/${TSMCLIENTSUBDIR}/ba/bin" ${DESTDIR}${EMULDIR}/etc/ld.so.conf; then \
		${ECHO} "/${TSMCLIENTSUBDIR}/ba/bin" >> ${DESTDIR}${EMULDIR}/etc/ld.so.conf; \
	fi; \
	if ! ${GREP} -q "/${TSMCLIENTSUBDIR}/api/bin" ${DESTDIR}${EMULDIR}/etc/ld.so.conf; then \
		${ECHO} "/${TSMCLIENTSUBDIR}/api/bin" >> ${DESTDIR}${EMULDIR}/etc/ld.so.conf; \
	fi
	${INSTALL_DATA_DIR} ${EG_DIR}
	${INSTALL_DATA} ${DESTDIR}${EMULDIR}/${TSMCLIENTSUBDIR}/ba/bin/dsm.*.smp ${EG_DIR}
	${INSTALL_DATA} ${FILESDIR}/tsm_daily.sh ${EG_DIR}
	${RM} -f ${PKG_SYSCONFDIR}/en_US && \
		${LN} -s ${DESTDIR}${EMULDIR}/${TSMCLIENTSUBDIR}/ba/bin/en_US/ ${TSM_LOCALE}

.include "../../mk/bsd.pkg.mk"
