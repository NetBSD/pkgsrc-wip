# $NetBSD$

RUST_VERSION=	1.15.1
DISTNAME=	rustc-${RUST_VERSION}-src
PKGNAME=	rustc-${RUST_VERSION}
CATEGORIES=	lang
MASTER_SITES=	https://static.rust-lang.org/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.rust-lang.org/
COMMENT=	Safe, concurrent, practical language
LICENSE=	mit OR apache-2.0

DIST_SUBDIR=	${PKGNAME_NOREV}

#BUILD_DEPENDS+=	curl-[0-9]*:../../www/curl

PYTHON_VERSIONS_ACCEPTED=	27 # as of 1.15.1
PYTHON_FOR_BUILD_ONLY=		yes

HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix=${PREFIX} \
			--mandir=${PREFIX}/${PKGMANDIR}
#CONFIGURE_ARGS+=	--llvm-root=${BUILDLINK_PREFIX.libLLVM}
#CONFIGURE_ARGS+=	--python=python
CONFIGURE_ARGS+=	--disable-jemalloc  # XXX NetBSD only?
#CONFIGURE_ARGS+=	--disable-codegen-tests # otherwise needs LLVM's FileCheck executable, which libLLVM doesn't install

USE_LANGUAGES=	c c++
GCC_REQD=	4.7 4.8
USE_TOOLS+=	bash gmake gsed perl tar

CHECK_PORTABILITY_SKIP+=	src/grammar/check.sh

# for guidance: http://www.ntecs.de/blog/2014/07/29/rust-ported-to-dragonflybsd/
# XXX problem with libtool wrapper
# XXX needs python during build

REPLACE_BASH+=	src/rust-installer/gen-install-script.sh
REPLACE_BASH+=	src/rust-installer/gen-installer.sh

#
# Lots of per-platform specific documentation, e.g. for each system call,
# making it difficult to PLIST.  If it ends up being important we'll just have
# to go with lots of PLIST.${OPSYS}
#
CONFIGURE_ARGS+=	--disable-docs

TEST_TARGET=	check

#
# Rust requires a binary stage0 kit to build itself, currently supported
# only on a limited number of platforms.  Details of the arch name and
# sha1 for supported platforms are kept in src/snapshots.txt
#
.include "../../mk/bsd.prefs.mk"
NOT_FOR_PLATFORM=	*-*-alpha *-*-vax # not targeted by LLVM
NOT_FOR_PLATFORM+=	*-*-sparc* # not targeted by Rust in this version
NOT_FOR_PLATFORM+=	Interix-*-* # not supported via pkgsrc, needs MinGW

RUST_STAGE0_VERSION:=	1.14.0
RUST_STAGE0_DATE:=	2016-12-18
RUST_CARGO0_DISTHASH:=	fbeea902d2c9a5be6d99cc35681565d8f7832592

DISTFILES:=		${DEFAULT_DISTFILES}

# Tier 1:
.if !empty(MACHINE_PLATFORM:MDarwin-*-i386) || make(distinfo) || \
	make(makesum) || make(mirror-distfiles) || make(upload-distfiles)
RUST_ARCH:=		i686-apple-darwin
RUST_STAGE0:=		rustc-${RUST_STAGE0_VERSION}-${RUST_ARCH}.tar.gz
RUST_STD0:=		rust-std-${RUST_STAGE0_VERSION}-${RUST_ARCH}.tar.gz
RUST_CARGO0:=		cargo-nightly-${RUST_ARCH}.tar.gz
SITES.${RUST_CARGO0}=	\
	https://s3.amazonaws.com/rust-lang-ci/cargo-builds/${RUST_CARGO0_DISTHASH}/
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD0} ${RUST_CARGO0}
.endif

.if !empty(MACHINE_PLATFORM:MDarwin-*-x86_64) || make(distinfo) || \
	make(makesum) || make(mirror-distfiles) || make(upload-distfiles)
RUST_ARCH:=		x86_64-apple-darwin
RUST_STAGE0:=		rustc-${RUST_STAGE0_VERSION}-${RUST_ARCH}.tar.gz
RUST_STD0:=		rust-std-${RUST_STAGE0_VERSION}-${RUST_ARCH}.tar.gz
RUST_CARGO0:=		cargo-nightly-${RUST_ARCH}.tar.gz
SITES.${RUST_CARGO0}=	\
	https://s3.amazonaws.com/rust-lang-ci/cargo-builds/${RUST_CARGO0_DISTHASH}/
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD0} ${RUST_CARGO0}
.endif

.if !empty(MACHINE_PLATFORM:MLinux-*-i386) || make(distinfo) || \
	make(makesum) || make(mirror-distfiles) || make(upload-distfiles)
RUST_ARCH:=		i686-unknown-linux-gnu
RUST_STAGE0:=		rustc-${RUST_STAGE0_VERSION}-${RUST_ARCH}.tar.gz
RUST_STD0:=		rust-std-${RUST_STAGE0_VERSION}-${RUST_ARCH}.tar.gz
RUST_CARGO0:=		cargo-nightly-${RUST_ARCH}.tar.gz
SITES.${RUST_CARGO0}=	\
	https://s3.amazonaws.com/rust-lang-ci/cargo-builds/${RUST_CARGO0_DISTHASH}/
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD0} ${RUST_CARGO0}
.endif

.if !empty(MACHINE_PLATFORM:MLinux-*-x86_64) || make(distinfo) || \
	make(makesum) || make(mirror-distfiles) || make(upload-distfiles)
RUST_ARCH:=		x86_64-unknown-linux-gnu
RUST_STAGE0:=		rustc-${RUST_STAGE0_VERSION}-${RUST_ARCH}.tar.gz
RUST_STD0:=		rust-std-${RUST_STAGE0_VERSION}-${RUST_ARCH}.tar.gz
RUST_CARGO0:=		cargo-nightly-${RUST_ARCH}.tar.gz
SITES.${RUST_CARGO0}=	\
	https://s3.amazonaws.com/rust-lang-ci/cargo-builds/${RUST_CARGO0_DISTHASH}/
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD0} ${RUST_CARGO0}
.endif

# Tier 2 (XXX currently incomplete):
.if !empty(MACHINE_PLATFORM:MNetBSD-*-x86_64) || make(distinfo) || \
	make(makesum) || make(mirror-distfiles) || make(upload-distfiles)
RUST_ARCH:=		x86_64-unknown-netbsd
RUST_STAGE0:=		rustc-${RUST_STAGE0_VERSION}-${RUST_ARCH}.tar.gz
RUST_STD0:=		rust-std-${RUST_STAGE0_VERSION}-${RUST_ARCH}.tar.gz
RUST_CARGO0:=		cargo-nightly-${RUST_ARCH}.tar.gz
SITES.${RUST_CARGO0}=	\
	https://s3.amazonaws.com/rust-lang-ci/cargo-builds/${RUST_CARGO0_DISTHASH}/
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD0} ${RUST_CARGO0}
.endif

.if !empty(MACHINE_PLATFORM:MFreeBSD-*-x86_64) || make(distinfo) || \
	make(makesum) || make(mirror-distfiles) || make(upload-distfiles)
RUST_ARCH:=		x86_64-unknown-freebsd
RUST_STAGE0:=		rustc-${RUST_STAGE0_VERSION}-${RUST_ARCH}.tar.gz
RUST_STD0:=		rust-std-${RUST_STAGE0_VERSION}-${RUST_ARCH}.tar.gz
RUST_CARGO0:=		cargo-nightly-${RUST_ARCH}.tar.gz
SITES.${RUST_CARGO0}=	\
	https://s3.amazonaws.com/rust-lang-ci/cargo-builds/${RUST_CARGO0_DISTHASH}/
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD0} ${RUST_CARGO0}
.endif

# Tier 3
#.if !empty(MACHINE_PLATFORM:MSunOS-*-x86_64) || make(distinfo) || \
#	make(makesum) || make(mirror-distfiles) || make(upload-distfiles)
#RUST_ARCH:=		x86_64-sun-solaris
#RUST_STAGE0:=		rustc-${RUST_STAGE0_VERSION}-${RUST_ARCH}.tar.gz
#DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD0} ${RUST_CARGO0}
#RUST_STD0:=		rust-std-${RUST_STAGE0_VERSION}-${RUST_ARCH}.tar.gz
#RUST_CARGO0:=		cargo-nightly-${RUST_ARCH}.tar.gz
#SITES.${RUST_CARGO0}=	\
#	https://s3.amazonaws.com/rust-lang-ci/cargo-builds/${RUST_CARGO0_DISTHASH}/
#.endif

.if empty(RUST_STAGE0) || empty(RUST_STD0) || empty(RUST_CARGO0)
PKG_FAIL_REASON:=	"Not currently aware of Stage 0 bootstrap kit for ${MACHINE_PLATFORM}"
.endif

PLIST_SRC=		PLIST
.if ${OPSYS} == "Darwin"
PLIST_SRC+=		PLIST.lldb
.else
PLIST_SRC+=		PLIST.gdb
.endif

OPSYSVARS+=		SOEXT
SOEXT.Darwin=		dylib
SOEXT.*=		so

PLIST_VARS+=		jemalloc

CONFIGURE_ARGS+=	--build=${RUST_ARCH}

#MAKE_ENV+=	RUSTC_FLAGS=-C\ link-arg=${COMPILER_RPATH_FLAG}${PREFIX}/lib/rustlib/${RUST_ARCH}/lib
MAKE_ENV+=	RUSTFLAGS=-C\ link-arg=${COMPILER_RPATH_FLAG}${PREFIX}/lib/rustlib/${RUST_ARCH}/lib

EXTRACT_ONLY=		${DEFAULT_DISTFILES}

PLIST_SUBST+=		RUST_ARCH=${RUST_ARCH:Q}
PLIST_SUBST+=		SOEXT=${SOEXT:Q}
PRINT_PLIST_AWK+=	{ gsub(/${RUST_ARCH}/, "$${RUST_ARCH}") }
PRINT_PLIST_AWK+=	{ gsub(/\.${SOEXT}/, ".$${SOEXT}") }
GENERATE_PLIST+=	cd ${DESTDIR}${PREFIX} && ${FIND} lib lib/rustlib/${RUST_ARCH}/lib \( -type f -or -type l \) -and -name 'lib*-*.*' | ${SORT} -dr;

post-extract:
	${MKDIR} ${WRKSRC}/build/cache/${RUST_STAGE0_DATE}
	${CP} -a ${DISTDIR}/${DIST_SUBDIR}/${RUST_STAGE0} ${WRKSRC}/build/cache/${RUST_STAGE0_DATE}/
	${CP} -a ${DISTDIR}/${DIST_SUBDIR}/${RUST_STD0} ${WRKSRC}/build/cache/${RUST_STAGE0_DATE}/
	${MKDIR} ${WRKSRC}/build/cache/${RUST_CARGO0_DISTHASH}
	${CP} -a ${DISTDIR}/${DIST_SUBDIR}/${RUST_CARGO0} ${WRKSRC}/build/cache/${RUST_CARGO0_DISTHASH}/

.if ${OPSYS} == "SunOS"
BUILD_DEPENDS+=		grep>=0:../../textproc/grep
BUILD_DEPENDS+=		coreutils>=0:../../sysutils/coreutils
TOOLS_PATH.grep=	${PREFIX}/bin/ggrep
#TOOLS_CREATE+=		md5sum
#TOOLS_PATH.md5sum=	${PREFIX}/bin/gmd5sum

SUBST_CLASSES+=		ranlib
SUBST_STAGE.ranlib=	pre-configure
SUBST_FILES.ranlib=	mk/rt.mk
SUBST_SED.ranlib=	-e 's,RANLIB=.* \\,RANLIB="true" \\,g'
.endif

INSTALL_TARGET=		dist

post-install:
	cd ${WRKDIR} && \
	${TAR} -pzxf ${WRKSRC}/build/dist/rust-std-${RUST_VERSION}-${RUST_ARCH}.tar.gz && \
	cd rust-std-${RUST_VERSION}-${RUST_ARCH} && \
	./install.sh --disable-ldconfig --disable-verify --destdir=${DESTDIR} --prefix=${PREFIX} --mandir=${PKGMANDIR}
	cd ${WRKDIR} && \
	${TAR} -pzxf ${WRKSRC}/build/dist/rustc-${RUST_VERSION}-${RUST_ARCH}.tar.gz && \
	cd ${WRKDIR}/rustc-${RUST_VERSION}-${RUST_ARCH} && \
	./install.sh --disable-ldconfig --disable-verify --destdir=${DESTDIR} --prefix=${PREFIX} --mandir=${PKGMANDIR}
	${RM} -f ${DESTDIR}${PREFIX}/lib/rustlib/install.log


#.include "../../lang/libLLVM/buildlink3.mk"
#.include "../../lang/llvm/buildlink3.mk"
#.include "../../lang/libunwind/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
