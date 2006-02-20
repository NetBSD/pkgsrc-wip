# $NetBSD: Makefile,v 1.7 2006/02/20 10:50:53 hfath Exp $

DISTNAME=	tsm-5.2.2
CATEGORIES=     sysutils
MASTER_SITES=	ftp://ftp.software.ibm.com/storage/tivoli-storage-management/maintenance/client/v5r2/Linux/Linux86/v522/
DISTFILES=	${RPMFILES}
RPMFILES=	TIVsm-BA.i386.rpm TIVsm-API.i386.rpm

MAINTAINER=	hf@spg.tu-darmstadt.de
HOMEPAGE=	http://www-3.ibm.com/software/tivoli/products/storage-mgr/
COMMENT=        IBM Tivoli Storage Manager Client

PKG_SYSCONFSUBDIR= tsm
FILESDIR=	${PKGDIR}/files
EG_DIR=		${PREFIX}/share/examples/tsm
CONF_FILES=	${EG_DIR}/dsm.sys.smp ${PKG_SYSCONFDIR}/dsm.sys \
		${EG_DIR}/dsm.opt.smp ${PKG_SYSCONFDIR}/dsm.opt

EXTRACT_ONLY=	# empty
NO_BUILD=	YES
PLIST_DYN=	${WRKDIR}/PLIST_DYNAMIC
PLIST_SRC=	${PLIST_DYN} ${PKGDIR}/PLIST
PLIST_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}
DIST_SUBDIR=	.

.include "../../mk/bsd.prefs.mk"

EMULSUBDIR=		emul/linux
EMULDIR=		${PREFIX}/${EMULSUBDIR}
TSMCLIENTSUBDIR=	opt/tivoli/tsm/client

MESSAGE_SUBST+=		EMULDIR=${EMULDIR:Q}

ONLY_FOR_PLATFORM= 	NetBSD-[2-9]*-i386

RPM2PKG=		${PREFIX}/sbin/rpm2pkg
BUILD_DEPENDS+=		rpm2pkg>=1.3:../../pkgtools/rpm2pkg

RPM2PKGSTRIP=		0
RPM2PKGARGS=		-d ${PREFIX} -f ${PLIST_DYN} -p ${EMULSUBDIR}
.for temp in ${RPMFILES}
RPM2PKGARGS+=		${DISTDIR}/${temp}
.endfor

# The SuSE Linux packages have circular dependencies.
LDD?=			${TRUE}

DEPENDS+=               suse_compat>=7.3:../../emulators/${SUSE_DIR_PREFIX}_compat
DEPENDS+=               suse_x11>=7.3:../../emulators/${SUSE_DIR_PREFIX}_x11

do-install:
	${RPM2PKG} ${RPM2PKGARGS}
	@if ${GREP} -q 'lib.*\.so' ${PLIST_DYN}; then \
	  ${ECHO_MSG} "===> [Automatic Linux shared object handling]"; \
	  if ! ${GREP} -q "/${TSMCLIENTSUBDIR}/ba/bin" ${EMULDIR}/etc/ld.so.conf; then \
	  ${ECHO} "/${TSMCLIENTSUBDIR}/ba/bin" >> ${EMULDIR}/etc/ld.so.conf; \
	  fi; \
	  if ! ${GREP} -q "/${TSMCLIENTSUBDIR}/api/bin" ${EMULDIR}/etc/ld.so.conf; then \
	  ${ECHO} "/${TSMCLIENTSUBDIR}/api/bin" >> ${EMULDIR}/etc/ld.so.conf; \
	  fi; \
	  ${EMULDIR}/sbin/ldconfig -r ${EMULDIR}; \
	  ${ECHO} "@exec %D/${EMULSUBDIR}/sbin/ldconfig -r %D/${EMULSUBDIR}" >>${PLIST_DYN}; \
	  ${ECHO} "@unexec %D/${EMULSUBDIR}/sbin/ldconfig -r %D/${EMULSUBDIR} 2>/dev/null" >>${PLIST_DYN}; \
	fi

.include "../../emulators/suse_linux/Makefile.application"

post-install:
	@${TEST} -f ${EMULDIR}/etc/mtab || ${LN} -fs /etc/fstab ${EMULDIR}/etc/mtab
	@${INSTALL_DATA_DIR} ${EG_DIR}
	@${INSTALL_DATA} ${EMULDIR}/${TSMCLIENTSUBDIR}/ba/bin/dsm.*.smp ${EG_DIR}
	@${INSTALL_DATA} ${FILESDIR}/tsm_daily.sh ${EG_DIR}
	@${RM} -f ${PKG_SYSCONFDIR}/en_US && ${LN} -s ${EMULDIR}/${TSMCLIENTSUBDIR}/ba/bin/en_US/ ${PKG_SYSCONFDIR}/en_US

.include "../../mk/bsd.pkg.mk"
