# $NetBSD$

DISTNAME=	crystal-0.35.0
CATEGORIES=	lang
DISTFILES+=	${PKGNAME_NOREV}.tar.gz

# TODO: Update when they put out a release with NetBSD support.
# Do not trust nia@
MASTER_SITES=	${MASTER_SITE_GITHUB:=niacat/}
MASTER_SITES+=	https://cdn.NetBSD.org/pub/pkgsrc/misc/nia/crystal/
GITHUB_PROJECT=	crystal
GITHUB_TAG=	00380c0038aae81be22e8128d5a092d66b2fdffb

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://crystal-lang.org/
COMMENT=	Statically typed, compiled language, with Ruby-like syntax
LICENSE=	apache-2.0

DEPENDS+=	mime-types-[0-9]*:../../misc/mime-types

USE_TOOLS+=	gmake pkg-config xz xzcat pax
USE_LANGUAGES=	c c++

# C++14 for LLVM extension
GCC_REQD+=	5

BUILD_DIRS=	.build .
TEST_DIRS=	.
TEST_TARGET=	std_spec

MAKE_FLAGS+=	release=1
MAKE_FLAGS+=	progress=1
MAKE_FLAGS+=	verbose=1
MAKE_FLAGS+=	threads=${MAKE_JOBS}

# XXX: Remove this once they start using pkg-config for all libs.
# XXX: This is awful.
MAKE_ENV+=	CRYSTAL_LIBRARY_PATH=${PREFIX}/lib:/usr/lib
MAKE_ENV+=	LD_LIBRARY_PATH=${PREFIX}/lib:/usr/lib

#
# Crystal has significant memory requirements to build itself
# and the compiler is probably not suitable for archs with low
# amounts of available address space.
#
# Otherwise, it should be easy to add support for POSIXy platforms
# with support in LLVM by writing some libc bindings and
# cross-compiling.
#
ONLY_FOR_PLATFORM+=	Darwin-*-x86_64
ONLY_FOR_PLATFORM+=	DragonFly-*-x86_64
ONLY_FOR_PLATFORM+=	FreeBSD-*-x86_64
#ONLY_FOR_PLATFORM+=	NetBSD-*-aarch64 TODO: get this working.
ONLY_FOR_PLATFORM+=	NetBSD-*-x86_64
#ONLY_FOR_PLATFORM+=	Linux-*-aarch64 TODO: get this working.
ONLY_FOR_PLATFORM+=	Linux-*-i386
ONLY_FOR_PLATFORM+=	Linux-*-x86_64

#
# On NetBSD the default ulimit -s of 4096 is not high enough to produce
# a working Crystal compiler (ulimit -s 6000 works).
#
# Can use 30+ minutes of CPU time.
#
UNLIMIT_RESOURCES+=	cputime stacksize

SUBST_CLASSES+=		mime
SUBST_STAGE.mime=	pre-build
SUBST_FILES.mime+=	src/crystal/system/unix/mime.cr
SUBST_SED.mime+=	-e 's,/usr/local,${PREFIX},g'

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-build
SUBST_FILES.prefix+=	src/compiler/crystal/codegen/link.cr
SUBST_VARS.prefix+=	PREFIX

.include "../../mk/bsd.prefs.mk"

#
# Crystal unfortunately requires itself to build.
#
# An object file for the Crystal parts of the compiler can be cross-compiled
# using any working Crystal compiler, and then linked with the required
# libraries and C/C++ parts by pkgsrc, then used to build you a new Crystal.
#
# These binaries were cross-compiled on a NetBSD/amd64 machine by nia@.
# The NetBSD/amd64 compiler was originally produced by cross-compiling
# from an Alpine Linux VM's crystal package.
#
# Therefore, the chain of trust is:
# - nia@NetBSD.org
# - Alpine Linux packages in early 2020, roughly when the
#   NetBSD port was being privately worked on.
# - crystal-lang maintainers
# - Intel, etc
#
DISTFILES:=		${DEFAULT_DISTFILES}
.if !empty(MACHINE_PLATFORM:MDarwin-*-x86_64) || make(distinfo) || make (makesum) || make(mdi)
CRYSTAL_ARCH=		x86_64-darwin
CRYSTAL_BOOT_VER=	0.34.0
CRYSTAL_BOOT_OBJ=	crystal-${CRYSTAL_BOOT_VER}-${CRYSTAL_ARCH}.o
DISTFILES:=		${DISTFILES} ${CRYSTAL_BOOT_OBJ}.xz
.endif
.if !empty(MACHINE_PLATFORM:MDragonFly-*-x86_64) || make(distinfo) || make (makesum) || make(mdi)
CRYSTAL_ARCH=		x86_64-darwin
CRYSTAL_BOOT_VER=	0.34.0
CRYSTAL_BOOT_OBJ=	crystal-${CRYSTAL_BOOT_VER}-${CRYSTAL_ARCH}.o
DISTFILES:=		${DISTFILES} ${CRYSTAL_BOOT_OBJ}.xz
.endif
.if !empty(MACHINE_PLATFORM:MFreeBSD-*-x86_64) || make(distinfo) || make (makesum) || make(mdi)
CRYSTAL_ARCH=		x86_64-freebsd
CRYSTAL_BOOT_VER=	0.34.0
CRYSTAL_BOOT_OBJ=	crystal-${CRYSTAL_BOOT_VER}-${CRYSTAL_ARCH}.o
DISTFILES:=		${DISTFILES} ${CRYSTAL_BOOT_OBJ}.xz
.endif
#.if !empty(MACHINE_PLATFORM:MNetBSD-*-aarch64) || make(distinfo) || make (makesum) || make(mdi)
#CRYSTAL_ARCH=		aarch64-netbsd
#CRYSTAL_BOOT_VER=	0.34.0
#CRYSTAL_BOOT_OBJ=	crystal-${CRYSTAL_BOOT_VER}-${CRYSTAL_ARCH}.o.xz
#DISTFILES:=		${DISTFILES} ${CRYSTAL_BOOT_OBJ}.xz
#.endif
.if !empty(MACHINE_PLATFORM:MNetBSD-*-x86_64) || make(distinfo) || make (makesum) || make(mdi)
CRYSTAL_ARCH=		x86_64-netbsd
CRYSTAL_BOOT_VER=	0.34.0
CRYSTAL_BOOT_OBJ=	crystal-${CRYSTAL_BOOT_VER}-${CRYSTAL_ARCH}.o
DISTFILES:=		${DISTFILES} ${CRYSTAL_BOOT_OBJ}.xz
.endif
#.if (!empty(MACHINE_PLATFORM:MLinux-*-aarch64) && !empty(GLIBC_VERSION)) || make(distinfo) || make (makesum) || make(mdi)
#CRYSTAL_ARCH=		aarch64-linux-gnu
#CRYSTAL_BOOT_VER=	0.34.0
#CRYSTAL_BOOT_OBJ=	crystal-${CRYSTAL_BOOT_VER}-${CRYSTAL_ARCH}.o
#DISTFILES:=		${DISTFILES} ${CRYSTAL_BOOT_OBJ}.xz
#.endif
#.if (!empty(MACHINE_PLATFORM:MLinux-*-aarch64) && empty(GLIBC_VERSION)) || make(distinfo) || make (makesum) || make(mdi)
#CRYSTAL_ARCH=		aarch64-linux-musl
#CRYSTAL_BOOT_VER=	0.34.0
#CRYSTAL_BOOT_OBJ=	crystal-${CRYSTAL_BOOT_VER}-${CRYSTAL_ARCH}.o
#DISTFILES:=		${DISTFILES} ${CRYSTAL_BOOT_OBJ}.xz
#.endif
.if (!empty(MACHINE_PLATFORM:MLinux-*-i386) && !empty(GLIBC_VERSION)) || make(distinfo) || make (makesum) || make(mdi)
CRYSTAL_ARCH=		i386-linux-gnu
CRYSTAL_BOOT_VER=	0.34.0
CRYSTAL_BOOT_OBJ=	crystal-${CRYSTAL_BOOT_VER}-${CRYSTAL_ARCH}.o
DISTFILES:=		${DISTFILES} ${CRYSTAL_BOOT_OBJ}.xz
.endif
.if (!empty(MACHINE_PLATFORM:MLinux-*-i386) && empty(GLIBC_VERSION)) || make(distinfo) || make (makesum) || make(mdi)
CRYSTAL_ARCH=		i386-linux-musl
CRYSTAL_BOOT_VER=	0.34.0
CRYSTAL_BOOT_OBJ=	crystal-${CRYSTAL_BOOT_VER}-${CRYSTAL_ARCH}.o
DISTFILES:=		${DISTFILES} ${CRYSTAL_BOOT_OBJ}.xz
.endif
.if (!empty(MACHINE_PLATFORM:MLinux-*-x86_64) && !empty(GLIBC_VERSION)) || make(distinfo) || make (makesum) || make(mdi)
CRYSTAL_ARCH=		x86_64-linux-gnu
CRYSTAL_BOOT_VER=	0.34.0
CRYSTAL_BOOT_OBJ=	crystal-${CRYSTAL_BOOT_VER}-${CRYSTAL_ARCH}.o
DISTFILES:=		${DISTFILES} ${CRYSTAL_BOOT_OBJ}.xz
.endif
.if (!empty(MACHINE_PLATFORM:MLinux-*-x86_64) && empty(GLIBC_VERSION)) || make(distinfo) || make (makesum) || make(mdi)
CRYSTAL_ARCH=		x86_64-linux-musl
CRYSTAL_BOOT_VER=	0.34.0
CRYSTAL_BOOT_OBJ=	crystal-${CRYSTAL_BOOT_VER}-${CRYSTAL_ARCH}.o
DISTFILES:=		${DISTFILES} ${CRYSTAL_BOOT_OBJ}.xz
.endif

.PHONY: build-cross-targets

build-cross-targets:
.for target in \
    i386-linux-gnu \
    i386-linux-musl \
    x86_64-darwin \
    x86_64-dragonfly \
    x86_64-freebsd \
    x86_64-netbsd \
    x86_64-linux-gnu \
    x86_64-linux-musl
	LIBRARY_PATH=${PREFIX}/lib:/usr/lib \
	cd ${WKSRC} && ${WRKSRC}/.build/crystal build \
		-o crystal-${PKGVERSION_NOREV}-${target} \
		--cross-compile --target ${target} \
		--progress --threads ${MAKE_JOBS} \
		src/compiler/crystal.cr \
		-D without_openssl \
		-D without_zlib \
		-D i_know_what_im_doing # do I?
	xz -0 crystal-${PKGVERSION_NOREV}-${target}.o
.endfor

pre-build:
	${MKDIR} ${WRKSRC}/.build
	${XZCAT} ${WRKDIR}/${CRYSTAL_BOOT_OBJ}.xz > ${WRKSRC}/.build/crystal.o
	${CP} -f ${FILESDIR}/Makefile ${WRKSRC}/.build/Makefile

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	lib/crystal
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/zsh/site-functions

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/.build/crystal \
		${DESTDIR}${PREFIX}/bin/crystal
	${INSTALL_MAN} ${WRKSRC}/man/crystal.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/crystal.1
	${INSTALL_DATA} ${WRKSRC}/etc/completion.bash \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/crystal
	${INSTALL_DATA} ${WRKSRC}/etc/completion.zsh \
		${DESTDIR}${PREFIX}/share/zsh/site-functions/_crystal
	cd ${WRKSRC}/src && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/lib/crystal
	${FIND} ${DESTDIR}${PREFIX}/lib/crystal -name '*.o' -or -name '*.a' -exec rm -f '{}' ';'

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
