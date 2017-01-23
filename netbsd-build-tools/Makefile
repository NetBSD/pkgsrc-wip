# $NetBSD$

PKGNAME=	netbsd-build-tools-7.0.2
MASTER_SITES=	http://cdn.netbsd.org/pub/NetBSD/NetBSD-${PKGVERSION_NOREV}/source/sets/
EXTRACT_SUFX=	.tgz
DISTFILES+=	gnusrc${EXTRACT_SUFX}
DISTFILES+=	sharesrc${EXTRACT_SUFX}
DISTFILES+=	src${EXTRACT_SUFX}
DISTFILES+=	syssrc${EXTRACT_SUFX}
CATEGORIES=	cross

MAINTAINER=	cfkoch@edgebsd.org
COMMENT=	NetBSD cross-toolchain
HOMEPAGE=	http://netbsd.org/

WRKSRC=		${WRKDIR}/usr/src
NO_CONFIGURE=	yes
USE_LANGUAGES+=	c c++ fortran

CHECK_PORTABILITY_SKIP+=	crypto/external/cpl/tpm-tools/dist/configure
CHECK_PORTABILITY_SKIP+=	external/bsd/llvm/dist/llvm/utils/buildit/build_llvm
CHECK_PORTABILITY_SKIP+=	external/gpl2/lvm2/dist/configure
CHECK_PORTABILITY_SKIP+=	external/gpl3/gdb/dist/gdb/config/djgpp/djconfig.sh

MAKE_ENV+=	MAKECONF=${FILESDIR}/mk.conf

BUILDSH_OBJDIR=		${WRKSRC}/../obj
BUILDSH_TOOLDIR=	${WRKSRC}/../tooldir

BUILDSH_FLAGS+=	-U
BUILDSH_FLAGS+=	-mamd64 # XXX should be an option
BUILDSH_FLAGS+=	-O${BUILDSH_OBJDIR}
BUILDSH_FLAGS+=	-T${BUILDSH_TOOLDIR}
BUILDSH_FLAGS+=	-N1

do-build:
	cd ${WRKSRC} && ${MAKE_ENV} ./build.sh ${BUILDSH_FLAGS} tools

# XXX blah, I haven't gotten here yet
#do-install:
#	${CP} -R ${BUILDSH_TOOLDIR} ${DESTDIR}${PREFIX}/cross/netbsd-${PKGNAME_NOREV}

.include "../../mk/bsd.pkg.mk"
