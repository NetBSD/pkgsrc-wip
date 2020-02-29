# $NetBSD: Makefile,v 1.1 2015/05/03 15:01:12 spz Exp $

COMPAT_PKG=		compat80	# for compat_netbsd/Makefile.common
NETBSD_VERSION=		8.0

HOMEPAGE=		https://www.NetBSD.org/releases/formal-8/index.html
COMMENT=		Shared X11 libraries for NetBSD 8.0 compatibility
LICENSE=		mit
CATEGORIES=		emulators

# EMUL_PLATFORMS=		netbsd-alpha netbsd-arm netbsd-i386 netbsd-m68k	\
# 			netbsd-mipseb netbsd-mipsel \
# 			netbsd-mips64eb netbsd-mips64el \
# 			netbsd-powerpc	\
# 			netbsd-sparc netbsd-sparc64 netbsd-x86_64

EMUL_PLATFORMS=		netbsd-i386
ONLY_FOR_PLATFORM=	NetBSD-[7-9]*-* NetBSD-[1-9][0-9]*-*

CHECK_RELRO_SUPPORTED=	no

#.include "../../emulators/compat_netbsd/Makefile.common"

DISTNAME=		compat80-x11-${EMUL_ARCH}-${COMPAT_VERSION}
COMPAT_VERSION=		8.0
DIST_SUBDIR=		18072019
MASTER_SITES=		https://cdn.NetBSD.org/pub/NetBSD/NetBSD-8.0/i386/binary/sets/

DISTFILES=		xbase.tgz xcomp.tgz xetc.tgz xfont.tgz xserver.tgz

# in this package we want the PLIST.alpha and PLIST.m68k to replace, not
# amend, the common PLIST
# .if exists(${PKGDIR}/PLIST.${EMUL_ARCH})
# PLIST_SRC=		${PKGDIR}/PLIST.${EMUL_ARCH}
# .endif

WRKSRC=			${WRKDIR}/usr/X11R7

NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${EMULSUBDIR}
	cd ${WRKSRC} && for dir in lib libexec usr; do          \
	if ${TEST} -d "$$dir"; then                             \
	pax -rw "$$dir"                                         \
	${DESTDIR}${PREFIX}/${EMULSUBDIR};                      \
	fi;                                                     \
	done


# pulling in later release compats through the main compat package

.include "../../mk/bsd.pkg.mk"
