# $NetBSD: Makefile,v 1.2 2015/05/03 15:01:11 spz Exp $

DISTNAME=		src
PKGNAME=		netbsd-pf-8.0
HOMEPAGE=		https://www.NetBSD.org/
CATEGORIES=		sysutils
MASTER_SITES+=		https://cdn.netbsd.org/pub/NetBSD/NetBSD-8.0/source/sets/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		PF module for NetBSD
LICENSE=		2-clause-bsd
EXTRACT_SUFX=		.tgz

DIST_SUBDIR=		NetBSD-8.0
DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		syssrc.tgz
ONLY_FOR_PLATFORM=	NetBSD-*-*

WRKSRC=		${WRKDIR}/usr/src/
KMOD=		pf.kmod
KMODULEDIR=	stand/${MACHINE}/${OS_VERSION}/modules/pf

INSTALLATION_DIRS+=	${KMODULEDIR} sbin/ man/man4 man/man5 man/man8
INSTALLATION_DIRS+=	man/html4 man/html5 man/html8 share/examples/pf

do-build:
	${MAKE_ENV} ${MAKE} -C ${WRKSRC}/usr.sbin/pf
	${MAKE_ENV} ${MAKE} -C ${WRKSRC}/sys/modules/pf/

do-install:
	${MAKE_ENV} ${MAKE} install -C ${WRKSRC}/usr.sbin/pf \
		BINDIR=${DESTDIR}${PREFIX}/sbin \
		FILESDIR=${DESTDIR}${PREFIX}/share/examples/pf
	${INSTALL_PROGRAM} ${WRKSRC}/sys/modules/pf/${KMOD} ${DESTDIR}${PREFIX}/${KMODULEDIR}

MAKE_ENV+=	MKCATPAGES=no		# Avoid inconsistency with PLIST
MAKE_ENV+=	NOGCCERROR=1		# XXX some build errors
MAKE_ENV+=	INSTPRIV=-U		# Support unprivileged install
MAKE_ENV+=	BSDSRCDIR=${WRKSRC}
MAKE_ENV+=	MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}

CHECK_PORTABILITY_SKIP+=	crypto/external/cpl/tpm-tools/dist/configure
CHECK_PORTABILITY_SKIP+=	external/bsd/libpcap/dist/configure
CHECK_PORTABILITY_SKIP+=	external/mit/expat/dist/configure

.include "../../mk/bsd.pkg.mk"
