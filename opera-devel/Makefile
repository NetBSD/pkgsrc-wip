# $NetBSD: Makefile,v 1.20 2007/07/30 15:49:10 jlamwww Exp $

DISTNAME=		opera-9.0beta1
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.hu-berlin.de/pub/www/opera/${OPERA_DIR}/
MASTER_SITES+=		http://ftp.sunet.se/pub/www/clients/Opera/${OPERA_DIR}/
MASTER_SITES+=		ftp://ftp.task.gda.pl/pub/opera/${OPERA_DIR}/
MASTER_SITES+=		ftp://ftp.tuwien.ac.at/infosys/browsers/opera/${OPERA_DIR}/
MASTER_SITES+=		ftp://opera.nsc.no/pub/nsc.no/mirrors/operasoftware/${OPERA_DIR}/
MASTER_SITES+=		ftp://ftp.opera.com/pub/opera/${OPERA_DIR}/
DISTFILES=		opera-${OPERA_DIST_VERSION}${OPERA_ARCH}-${OPERA_LANG}${EXTRACT_SUFX}

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://snapshot.opera.com/
COMMENT=		Small, fast and customizable WWW client

LICENSE=		opera-850-license

EMUL_PLATFORMS=		freebsd-i386
EMUL_PLATFORMS+=	linux-i386
EMUL_PLATFORMS+=	solaris-sparc

EMUL_MODULES.linux=	x11
SUSE_VERSION_REQD=	7.3

USE_LANGUAGES=		# empty
BUILD_DIRS=		# empty
EMUL_PKG_FMT=		plain

OPERA_LANG=		en
OPERA_VER_DATE=		20060411
OPERA_PKG_VERSION=	9.0
OPERA_PKG_VERSION_DIR=	900/beta1

.include "../../mk/bsd.prefs.mk"

# This package installs from an RPM directly into "/usr" on a Linux
# system, which can't be managed by pkgsrc.
#
NOT_FOR_PLATFORMS=      Linux-*-*

.if ${EMUL_PLATFORM} == "linux-i386"
EXTRACT_SUFX=		.rpm
OPERA_ARCH=		.i386
OPERA_DIR=		linux/${OPERA_PKG_VERSION_DIR}/${OPERA_LANG}/${OPERA_ARCH:S/.//}/static
OPERA_DIST_VERSION=	${OPERA_PKG_VERSION:C/beta.*//:C/u.*//}-${OPERA_VER_DATE}.1-static-qt

WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty

EMUL_PKG_FMT=		rpm
RPM2PKG_PREFIX=		${PREFIX}
RPM2PKG_SUBPREFIX=	${EMULSUBDIR}
RPM2PKG_STAGE=		do-install

do-build:
	${SED} -e 's#@EMULDIR@#${EMULDIR}#g'				\
		${FILESDIR}/opera.sh > ${WRKDIR}/opera

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/opera ${PREFIX}/bin
	${LN} -fs ${EMULDIR}/usr/share/man/man1/opera.1			\
		${PREFIX}/${PKGMANDIR}/man1
	${ECHO} "bin/opera" >> ${RPM2PKG_PLIST}
	${ECHO} "${PKGMANDIR}/man1/opera.1" >> ${RPM2PKG_PLIST}

.elif ${EMUL_PLATFORM} == "freebsd-i386"
ONLY_FOR_PLATFORM+=	FreeBSD-*-i386
EXTRACT_SUFX=		.tar.bz2
OPERA_ARCH=		.i386.freebsd
OPERA_DIR=		unix/freebsd/${OPERA_PKG_VERSION_DIR}/${OPERA_LANG}/static
OPERA_DIST_VERSION=	${OPERA_PKG_VERSION:C/u.*//}-${OPERA_VER_DATE}.1-static-qt
DISTFILES=		opera-${OPERA_DIST_VERSION}${OPERA_ARCH}-${OPERA_LANG}-236${EXTRACT_SUFX}

WRKSRC=			${WRKDIR}/opera-${OPERA_DIST_VERSION}${OPERA_ARCH}-${OPERA_LANG}

OWN_DIRS=		${PREFIX}/share/opera/plugins

.elif ${EMUL_PLATFORM} == "solaris-sparc"
ONLY_FOR_PLATFORM+=	SunOS-*-sparc*
EXTRACT_SUFX=		.tar.bz2
SOLARIS_VERSION_REQD=	8
OPERA_ARCH=		-sol8-sparc-local
OPERA_DIR=		unix/solaris/${OPERA_PKG_VERSION_DIR}/${OPERA_LANG}/${_OPERA_MACHINE_ARCH}/static
OPERA_DIST_VERSION=	${OPERA_PKG_VERSION:C/u.*//}-${OPERA_VER_DATE}.1-static-qt
DISTFILES=		opera-${OPERA_DIST_VERSION}${OPERA_ARCH}-${OPERA_LANG}-236${EXTRACT_SUFX}

WRKSRC=			${WRKDIR}/opera-${OPERA_DIST_VERSION}${OPERA_ARCH}-${OPERA_LANG}

BUILD_DEFS+=		INSTALL_ETC_OPERARC
INSTALL_ETC_OPERARC?=	no
OWN_DIRS=		${PREFIX}/lib/opera/plugins

.  if !empty(INSTALL_ETC_OPERARC:M[yY][eE][sS])
CONF_FILES+=		${PREFIX}/share/opera/config/opera6rc \
			/etc/opera6rc
CONF_FILES+=		${PREFIX}/share/opera/config/opera6rc.fixed \
			/etc/opera6rc.fixed
.  endif
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

PLIST_SUBST+=		OPERA_VER_DATE=${OPERA_VER_DATE:Q}
PLIST_SUBST+=		OPERA_PKG_VERSION=${OPERA_PKG_VERSION:C/u.*//}

.if ${EMUL_PKG_FMT} == "plain"
SUBST_CLASSES+=		opera
SUBST_STAGE.opera=	post-build
SUBST_FILES.opera=	man/opera.1
SUBST_SED.opera=	-e 's,/usr/,${PREFIX}/,g'

do-install:
	@cd ${WRKSRC} && ${ECHO} "n" | ./install.sh --prefix=${PREFIX}
	@${ECHO} "=> You can ignore any previous lines about opera6rc"
	@${ECHO}

post-install:
	@${INSTALL_MAN} ${WRKSRC}/man/opera.1 ${PREFIX}/${PKGMANDIR}/man1
.endif

.include "../../mk/bsd.pkg.mk"
