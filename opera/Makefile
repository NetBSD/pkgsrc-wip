# $NetBSD: Makefile,v 1.7 2010/07/01 05:13:48 obache Exp $

DISTNAME=		opera-${OPERA_PKG_VERSION}${OPERA_DIST_SEP}${OPERA_DIST_SUFFIX}
PKGNAME=		opera-${OPERA_PKG_VERSION:S/u/pl/}
CATEGORIES=		www
MASTER_SITES+=		http://ftp.sunet.se/pub/www/clients/Opera/${OPERA_DIR}/
MASTER_SITES+=		ftp://ftp.hu-berlin.de/pub/www/opera/${OPERA_DIR}/
MASTER_SITES+=		ftp://ftp.task.gda.pl/pub/opera/${OPERA_DIR}/
MASTER_SITES+=		ftp://ftp.tuwien.ac.at/infosys/browsers/opera/${OPERA_DIR}/
MASTER_SITES+=		ftp://opera.nsc.no/pub/nsc.no/mirrors/operasoftware/${OPERA_DIR}/
MASTER_SITES+=		ftp://ftp.opera.com/pub/opera/${OPERA_DIR}/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.opera.com/
COMMENT=		Small, fast and customizable WWW client
LICENSE=		opera-1000-license
LICENSE_FILE=		opera-1000-license

EMUL_PLATFORMS=		freebsd-i386 freebsd-x86_64
EMUL_PLATFORMS+=	linux-i386 linux-x86_64 linux-powerpc
EMUL_PLATFORMS+=	solaris-sparc solaris-i386

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=		# empty
NO_BUILD=		yes

OPERA_LANG=		en
OPERA_VER_DATE=		20090830
OPERA_PKG_BUILD=	4791
OPERA_PKG_VERSION=	10.11
OPERA_PKG_VERSION_DIR=	1011

PLIST_VARS+=		ia32w

.if ${EMUL_OPSYS} == "linux"
EMUL_MODULES.linux=	qt3 aspell
EMUL_REQD=		suse>=10.0
OPERA_ARCH.i386=	i386
OPERA_ARCH.x86_64=	x86_64
OPERA_ARCH.powerpc=	ppc
OPERA_VARIANT=		gcc4-shared-qt3
OPERA_OPSYS_SUBDIR=	linux
OPERA_PKG_BUILT_SUBDIR=	final
.  if ${EMUL_ARCH} != "x86_64"
OPERA_LINKAGE_SUBDIR=	shared
.  endif
.  if ${EMUL_ARCH} != "powerpc"
PLIST.ia32w=		yes
.  endif
OPERA_DIST_SUFFIX=	${OPERA_VARIANT}.${OPERA_ARCH}
OPERA_DIST_SEP=		.

.if !defined(EMUL_IS_NATIVE)
post-tools: emul-md5sum

.PHONY: emul-md5sum
emul-md5sum:
	${TEST} -x ${EMULDIR}/usr/bin/md5sum && ${LN} -s ${EMULDIR}/usr/bin/md5sum ${TOOLS_DIR}/bin/md5sum
.endif

.elif ${EMUL_OPSYS} == "freebsd"
OPERA_ARCH.i386=	intel
OPERA_DIST_ARCH.i386=	i386
OPERA_ARCH.x86_64=	amd64
OPERA_VARIANT=		freebsd7-shared-qt3
OPERA_OPSYS_SUBDIR=	unix/freebsd
OPERA_LINKAGE_SUBDIR=	shared
OPERA_DIST_SUFFIX=	${OPERA_VARIANT}.${OPERA_DIST_ARCH}
OPERA_DIST_SEP=		-
.elif ${EMUL_OPSYS} == "solaris"
OPERA_ARCH.sparc=	sparc
OPERA_ARCH.i386=	intel
OPERA_VARIANT=		gcc4-static-qt3
OPERA_OPSYS_SUBDIR=	unix/solaris
OPERA_DIST_SUFFIX=	${OPERA_VARIANT}
OPERA_DIST_SEP=		.
.  if ${EMUL_ARCH} == "sparc"
OPERA_LINKAGE_SUBDIR=	static
.  endif
.endif
OPERA_ARCH=		${OPERA_ARCH.${EMUL_ARCH}:U${EMUL_ARCH}}
OPERA_DIST_ARCH=	${OPERA_DIST_ARCH.${EMUL_ARCH}:U${OPERA_ARCH}}
OPERA_DIR=		${OPERA_OPSYS_SUBDIR}/${OPERA_PKG_VERSION_DIR}/${OPERA_PKG_BUILT_SUBDIR}/${OPERA_LANG}/${OPERA_ARCH}/${OPERA_LINKAGE_SUBDIR}
DIST_SUBDIR=		opera/${EMUL_PLATFORM}
EXTRACT_SUFX=		.tar.bz2

WRKSRC=			${WRKDIR}/opera-${OPERA_PKG_VERSION}-${OPERA_PKG_BUILD}.${OPERA_DIST_SUFFIX}

FULLMANDIR=		${PREFIX}/${PKGMANDIR}

SUBST_CLASSES+=		man
SUBST_STAGE.man=	post-install
SUBST_FILES.man=	${DESTDIR}${FULLMANDIR}/man1/opera.1
SUBST_SED.man=		-e 's,/usr/,${PREFIX}/,g'

SUBST_CLASSES+=		plugin
SUBST_STAGE.plugin=	post-install
SUBST_FILES.plugin=	${DESTDIR}${PREFIX}/share/opera/defaults/pluginpath.ini
SUBST_SED.plugin=	-e 's,/usr/local/,${PREFIX}/,g'

do-install:
	${RUN} cd ${WRKSRC};				\
	(${ECHO} "n"; ${ECHO} "n") | 			\
		./install.sh --prefix=${PREFIX:Q} --mandir=${FULLMANDIR:Q} \
			--DESTDIR=${DESTDIR:Q}

.include "../../mk/bsd.pkg.mk"
