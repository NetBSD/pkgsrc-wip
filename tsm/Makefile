# $NetBSD: Makefile,v 1.4 2004/09/13 15:52:24 hfath Exp $

DISTNAME=	tsm-5.2.2
CATEGORIES=     sysutils
MASTER_SITES=	ftp://ftp.software.ibm.com/storage/tivoli-storage-management/maintenance/client/v5r2/Linux/Linux86/v522/
DISTFILES=	${RPMFILES}

MAINTAINER=	strawberry@toth.org.uk
HOMEPAGE=	http://www-3.ibm.com/software/tivoli/products/storage-mgr/
COMMENT=        IBM Tivoli Storage Manager Client

EXTRACT_ONLY=	# empty
NO_BUILD=	YES
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC
RPMFILES=	TIVsm-BA.i386.rpm TIVsm-API.i386.rpm

.include "../../emulators/suse_linux/arch.mk"
.include "../../mk/bsd.prefs.mk"

MANCOMPRESSED?=		yes

EMULSUBDIR=		emul/linux
EMULDIR=		${PREFIX}/${EMULSUBDIR}

ONLY_FOR_PLATFORM= 	*-*-i386
.if (${OPSYS} != "Linux") && (${MACHINE_ARCH} == "i386")
DEPENDS+=		suse_compat>=6.4:../../emulators/suse_compat
DEPENDS+=		suse_x11>6.4:../../emulators/suse_x11
.endif

RPM2PKG=		${PREFIX}/sbin/rpm2pkg
BUILD_DEPENDS+=		rpm2pkg>=1.3:../../pkgtools/rpm2pkg

BUILD_DEFS+=		RPMFILES
.if defined(RPMIGNOREPATH)
BUILD_DEFS+=		RPMIGNOREPATH
.endif

# The SuSE Linux packages have circular dependencies.
LDD?=			${TRUE}

RPM2PKGARGS=		-d ${PREFIX} -f ${PLIST_SRC} -p ${EMULSUBDIR}
.for TEMP in ${RPMIGNOREPATH}
RPM2PKGARGS+=		-i ${TEMP}
.endfor
.for TEMP in ${RPMFILES}
RPM2PKGARGS+=		${DISTDIR}/${TEMP}
.endfor

do-install:
	${RPM2PKG} ${RPM2PKGARGS}
	@if ${GREP} -q 'lib.*\.so' ${PLIST_SRC}; then \
	  ${ECHO_MSG} "===> [Automatic Linux shared object handling]"; \
	  ${ECHO} "/opt/tivoli/tsm/client/ba/bin" >> ${EMULDIR}/etc/ld.so.conf; \
	  ${ECHO} "/opt/tivoli/tsm/client/api/bin" >> ${EMULDIR}/etc/ld.so.conf; \
	  ${EMULDIR}/sbin/ldconfig -r ${EMULDIR}; \
	  ${ECHO} "@exec %D/${EMULSUBDIR}/sbin/ldconfig -r %D/${EMULSUBDIR}" >>${PLIST_SRC}; \
	  ${ECHO} "@unexec %D/${EMULSUBDIR}/sbin/ldconfig -r %D/${EMULSUBDIR} 2>/dev/null" >>${PLIST_SRC}; \
	fi

show-shlib-type:
	@${ECHO} linux-${MACHINE_ARCH}

post-install:
	${TEST} -f ${EMULDIR}/etc/mtab || ${LN} -s /etc/fstab ${EMULDIR}/etc/mtab

.include "../../mk/bsd.pkg.mk"
