# $NetBSD: Makefile,v 1.4 2005/01/25 19:47:15 matthewluckie Exp $

DISTNAME=		nss-3.9.2
CATEGORIES=		security
MASTER_SITES?=		ftp://ftp.mozilla.org/pub/mozilla.org/security/nss/releases/NSS_3_9_2_RTM/src/

MAINTAINER=		mjl@luckie.org.nz
HOMEPAGE=		http://www.mozilla.org/projects/security/pki/nss/
COMMENT=		Libraries to support development of security-enabled applications

BUILD_DEPENDS+=		zip>=2.3:../../archivers/zip

WRKSRC=			${WRKDIR}/${DISTNAME}/mozilla/security/nss

USE_BUILDLINK3=		YES
USE_PERL5=		build
USE_GNU_TOOLS+=		make
CFLAGS+=		-I${LOCALBASE}/include/nspr
DIST=			${WRKSRC}/../../dist
BUILD_TARGET=		nss_build_all
MAKE_ENV=		BSD_LDOPTS="-L${LOCALBASE}/lib" BUILD_OPT=1
MAKE_ENV+=		LIBRUNPATH=${PREFIX}/lib

.include		"../../mk/bsd.prefs.mk"

.if ${OBJECT_FMT} == "ELF"
SO_SUFFIX=		so
SCRIPTS_ENV+=		NSS_INSTALL_LIB="${INSTALL_PROGRAM}"
.elif ${OBJECT_FMT} == "Mach-O"
SO_SUFFIX=		dylib
SCRIPTS_ENV+=		NSS_INSTALL_LIB="${INSTALL_LIB}"
.else
SO_SUFFIX=		so.1.0
SCRIPTS_ENV+=		NSS_INSTALL_LIB="${INSTALL_PROGRAM}"
.endif
PLIST_SUBST+=		SO_SUFFIX=${SO_SUFFIX}

SCRIPTS_ENV+=		RM=${RM:Q}
SCRIPTS_ENV+=		PLIST_SRC=${PLIST_SRC:Q}
SCRIPTS_ENV+=		SED=${SED:Q}
SCRIPTS_ENV+=		EGREP=${EGREP:Q}
SCRIPTS_ENV+=		SO_SUFFIX=${SO_SUFFIX:Q}
SCRIPTS_ENV+=		DIST=${DIST:Q}
SCRIPTS_ENV+=		OPSYS=${OPSYS:Q}
SCRIPTS_ENV+=		OS_VERSION=${OS_VERSION:Q}

do-install:
	${SETENV} ${SCRIPTS_ENV} ${SH} ${FILESDIR}/nss-install

.include "../../devel/nspr/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

