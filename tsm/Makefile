# $NetBSD: Makefile,v 1.1 2003/06/19 20:26:48 sfberry Exp $

DISTNAME=	TIVsm-BA.i386
PKGNAME=	tsm-5.16
CATEGORIES=     sysutils
MASTER_SITES=	ftp://ftp.software.ibm.com/storage/tivoli-storage-management/maintenance/client/v5r1/Linux/Linux86/v516/
EXTRACT_SUFX=	.rpm

MAINTAINER=	strawberry@toth.org.uk
HOMEPAGE=	http://www-3.ibm.com/software/tivoli/products/storage-mgr/
COMMENT=        IBM Tivoli Storage Manager Client

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} != "Linux") && (${MACHINE_ARCH} == "i386")
DEPENDS+=	suse_compat>=6.4:../../emulators/${SUSE_DIR_PREFIX}_compat
DEPENDS+=	suse_x11>6.4:../../emulators/${SUSE_DIR_PREFIX}_x11
.endif

BUILD_DEPENDS+= rpm2pkg>=1.3:../../pkgtools/rpm2pkg

ONLY_FOR_PLATFORM= *-*-i386
RPM2PKG=    	${PREFIX}/sbin/rpm2pkg
LDD?=		${TRUE}

EXTRACT_ONLY=	# empty
NO_BUILD=	YES
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC
RPM_FILES=	${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

# dsm tools will abort if the config file is not found
do-install:
	${RPM2PKG} -d ${PREFIX} -f ${PLIST_SRC} -p emul/linux ${RPM_FILES}
	${TOUCH} ${PREFIX}/emul/linux/opt/tivoli/tsm/client/ba/bin/dsm.sys

.include "../../mk/bsd.pkg.mk"
