# $NetBSD$

# This package is for NetBSD amd64, a.k.a. x86_64 only!
# Everything related to other OSs and/or target platforms has been stripped off.
# The beta channel has several iterations along the path to next stable.
# Regenerating checksums may be needed to build the current rust-beta.

DISTNAME=	rustc-beta-src
PKGNAME=	rust-1.96.0
CATEGORIES=	lang
MASTER_SITES=	https://static.rust-lang.org/dist/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://www.rust-lang.org/
COMMENT=	Safe, concurrent, practical language
LICENSE=	mit OR apache-2.0

# This package actually conflicts with lang/rust itself and with any stable wip
# version of it. Use either stable or beta, not both.
CONFLICTS+=	rust-bin-[0-9]*

# LLVM uses -std=c++17
USE_CXX_FEATURES+=	c++17
USE_GCC_RUNTIME=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		bash grep gmake perl:build pkg-config

HAS_CONFIGURE=		yes
PYTHON_FOR_BUILD_ONLY=	tool
CONFIG_SHELL=		${TOOL_PYTHONBIN}
CONFIGURE_SCRIPT=	src/bootstrap/configure.py
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--python=${TOOL_PYTHONBIN}
CONFIGURE_ARGS+=	--release-channel=stable
CONFIGURE_ARGS+=	--local-rust-root=${RUST_BOOTSTRAP_PATH}
CONFIGURE_ARGS+=	--enable-extended
CONFIGURE_ARGS+=	--enable-rpath
CONFIGURE_ARGS+=	--disable-codegen-tests
CONFIGURE_ARGS+=	--disable-compiler-docs
CONFIGURE_ARGS+=	--disable-llvm-static-stdcpp
CONFIGURE_ARGS+=	--disable-ninja
CONFIGURE_ARGS+=	--dist-compression-formats=xz
CONFIGURE_ARGS+=	--set dist.vendor=false

REPLACE_BASH+=		library/portable-simd/subtree-sync.sh
CB=			library/compiler-builtins
REPLACE_BASH+=		${CB}/ci/bench-icount.sh
REPLACE_BASH+=		${CB}/ci/miri.sh
REPLACE_BASH+=		${CB}/ci/run-docker.sh
REPLACE_BASH+=		${CB}/ci/run-extensive.sh
REPLACE_BASH+=		${CB}/ci/run.sh

REPLACE_PYTHON+=	${CB}/ci/ci-util.py
REPLACE_PYTHON+=	${CB}/etc/update-api-list.py

# This should allow us to perform "offline" builds (so cargo doesn't fetch
# dependencies during the build stage) but this isn't hooked up yet.
CONFIGURE_ARGS+=	--enable-vendor

# cargo defaults to using the number of available CPUs
MAKE_ENV+=		CARGO_BUILD_JOBS=${_MAKE_JOBS_N}

UNLIMIT_RESOURCES+=	cputime stacksize datasize virtualsize

TEST_TARGET=	check

# bin/* lib/*, but names vary
CHECK_RELRO_SUPPORTED=	no
CHECK_SSP_SUPPORTED=	no

.include "../../mk/bsd.prefs.mk"

# Getting RPATH with $ORIGIN into the bootstrap binaries is problematic,
# since pkgsrc refuses to put $ORIGIN into RPATHs of executables.
# So instead we need these so that the bootstrap compiler can be run out
# of the $RUST_BOOTSTRAP_PATH directory as part of the initial part of the
# rust compiler build.
# This problem is not present with the amd64 bootstrap bits,
# which are built by upstream and uses $ORIGIN/../lib in RPATH.
MAKE_ENV+=		LD_LIBRARY_PATH=${RUST_BOOTSTRAP_PATH:Q}/lib
PKGSRC_MAKE_ENV+=	LD_LIBRARY_PATH=${RUST_BOOTSTRAP_PATH:Q}/lib

# Allow overriding MAKE_JOBS_SAFE
.if !empty(rust.MAKE_JOBS_SAFE)
.  if ${rust.MAKE_JOBS_SAFE:tl} == "yes"
MAKE_JOBS_SAFE=		yes
.  endif
.endif

.if !empty(rust.BUILD_TARGET)
BUILD_TARGET=	${rust.BUILD_TARGET}
.endif

BUILD_TARGET?=		build

# Under NetBSD, do not use DT_RUNPATH
BUILDLINK_TRANSFORM+=	rm:-Wl,--enable-new-dtags

# Rust unfortunately requires itself to build.  The upstream-provided
# bootstrap for NetBSD/amd64 uses $ORIGIN/../lib in its RPATH and
# does not need any special post-processing.
DISTFILES:=		${DEFAULT_DISTFILES}

RUST_STAGE0_VER=	1.95.0
RUST_ARCH=		x86_64-unknown-netbsd
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.xz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}

# You may override RUST_BOOTSTRAP_PATH and RUST_ARCH in mk.conf
# if you have a local bootstrap compiler.
RUST_BOOTSTRAP_PATH?=	${WRKDIR}/rust-bootstrap

RUSTLIB_COMPILER=	lib/rustlib/rustc-src/rust/compiler
RUSTC_CG_CRANELIFT=	${RUSTLIB_COMPILER}/rustc_codegen_cranelift

CHECK_INTERPRETER_SKIP+=	${RUSTC_CG_CRANELIFT}/scripts/filter_profile.rs
CHECK_INTERPRETER_SKIP+=	${RUSTC_CG_CRANELIFT}/scripts/rustup.sh
CHECK_INTERPRETER_SKIP+=	${RUSTC_CG_CRANELIFT}/scripts/test_bootstrap.sh
CHECK_INTERPRETER_SKIP+=	${RUSTC_CG_CRANELIFT}/scripts/test_rustc_tests.sh
CHECK_INTERPRETER_SKIP+=	${RUSTC_CG_CRANELIFT}/.github/scripts/free-disk-space.sh
CHECK_INTERPRETER_SKIP+=	${RUSTLIB_COMPILER}/rustc_codegen_gcc/y.sh
CHECK_INTERPRETER_SKIP+=	lib/rustlib/src/rust/library/backtrace/ci/*.sh
CHECK_INTERPRETER_SKIP+=	lib/rustlib/src/rust/library/core/src/unicode/printable.py
CHECK_INTERPRETER_SKIP+=	lib/rustlib/src/rust/library/stdarch/ci/*.sh
CHECK_PORTABILITY_SKIP+=	tests/run-make/dump-ice-to-disk/check.sh
CHECK_PORTABILITY_SKIP+=	vendor/libdbus-sys-0.2.5/vendor/dbus/tools/cmake-format

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix+=	src/bootstrap/src/core/builder/cargo.rs
SUBST_FILES.prefix+=	src/bootstrap/bootstrap.py
SUBST_VARS.prefix=	PREFIX

# Generate list of subst entries for various .cargo-checksum.json files.
CKSUM_CRATES+=	vendor/openssl-src-300.5.0+3.5.0
CKSUMS+=	16c0b9fa70475cfb50ac21ad4ce049b494c45b3270fed386013785a28abb8d0a
CKSUMS+=	e2817c457afa7efc0f2ca62ce9dab5254eb5ddd9a5fd9e75bba2789be92c7b14
CKSUMS+=	6e62515e67910aea2f04b64c643aa2545732f9dd7bf0abf87d8accf8c2c1fb88
CKSUMS+=	ccc5252660386fbfec2d66423f2dc87e6da74efd39ca0fcd7c7fd583056725c1
CKSUMS+=	ac5501e7bff0f4384db0537307b362bf1bcb120d8b5859e5f08bd796e78feaea
CKSUMS+=	6d2c2831119e059d35e81a89b08195a29e325f68acfd86a3a7157ebf8e78182d

CKSUM_CRATES+=	vendor/openssl-src-300.5.4+3.5.4
CKSUMS+=	33f1e78110293a8558ae997ed57e7aac72c5bfd47a241dc7f6e2ffa98b7a7137
CKSUMS+=	d0232a8b63c2fb396ed7551eb983b16b6ebafbba4b33d4434e167b05ee290f8f

CKSUM_CRATES+=	vendor/openssl-sys-0.9.107
CKSUMS+=	a0d47c624273b43b4250cff5fa2f9b75e4199ca76897608563b526aedcdf3a16
CKSUMS+=	fcfc15ca30e1f881ed46cf57597a72bd2a8307269d0394c905f23e076a983e12
CKSUMS+=	e6d478786035538d721d88b7736f602c965a38687a805cb377ebbe0ea1a14617
CKSUMS+=	e2b2473bdf7ce5f854fcef6f07f984accc53b4382dba160d625c1fcbaba31612

CKSUM_CRATES+=	vendor/openssl-sys-0.9.109
CKSUMS+=	112fcb6f18b81f31c23c60e7be5fddc87603c05a595f2e22b6e8f7ed2ea89e5f
CKSUMS+=	023a3e755d7d4c5ca6e4f8ce7a8b1dc2dd1e50cbfcaa43cc6fe809b251ee7037
CKSUMS+=	f66ce762ec63c28621a0d6d48bd5872b96e71f0bfb6f88576a6e2cba0c229e12
CKSUMS+=	656834a8bd87476b074f36bcc2aeb33a74a0a0a6db5d140c35c4b3eb385afebe

CKSUM_CRATES+=	vendor/openssl-sys-0.9.111
CKSUMS+=	0c5a4bd38ed007182cfec3cf0824a4806e5c629b9d69e3cc2a5b6e9be3eec280
CKSUMS+=	777a22f3cd39ad01f2e559ecf600bb9c03ec42e0b9fbe41746f42938e162d523
CKSUMS+=	d17fa8715a43ff0da872ac504abb2cc0a395644e8f5c8c128812758c458d5963
CKSUMS+=	02d5de4e4976450f8e665e0eff664e93063dd53aec2cb75ecee0847e3c0c086e

CKSUM_CRATES+=	vendor/libc-0.2.155
CKSUMS+=	3e550d95419169febf094c425451ca86b12821fa17839b4b0ba7520b145a5820
CKSUMS+=	1cf38d9ddeca5295821b4234e17e1fc749f35b00307bdfdacb24c6892a288ad6
CKSUMS+=	b8d6f089fc8eb2cb59e45335a26c9ce871b846216c9859b553c6b91982f8de33
CKSUMS+=	d8c4a979ce9b406fb63c5aaf2827b616689294331341737fec392b8faa2126fa

CKSUM_CRATES+=	vendor/libc-0.2.169
CKSUMS+=	dc216609dfc6b2835e26f8c3e70f4c7c65425933eef04538de603f51e9429ec5
CKSUMS+=	04004bda0ea97d55c3588a7d82fa1faf0d150c5390250a298216ff3cc899b911
CKSUMS+=	b5dae853ebfc3355b155f8c20f3a481517bce27e164e304f56dfff172e313098
CKSUMS+=	55fb7f2c0877231286b2b6515e08eda1d5cac1311a402d0aa162c7eb867ee19b
CKSUMS+=	0b1936bad97b3a272c2d323d3435f6860fc355abe7603ca7ed8c4166cac75cc5
CKSUMS+=	1eb383a057cdf2826d884b19142bf0b68b6b30c5bc20baf7ee10401a92a8ef22

CKSUM_CRATES+=	vendor/lzma-sys-0.1.20
CKSUMS+=	6fd5e9245db34c6f557b8bfcaf03db82fc88c3b06dbfbb5f03b2bcd138983ef9
CKSUMS+=	2a68e3e635dce81c7dba25b3d3abfaa894ee729e1604f2d000ae3e201f7739a4

SUBST_CLASSES+=		cksum
SUBST_STAGE.cksum=	pre-configure
.for crate in ${CKSUM_CRATES}
SUBST_FILES.cksum+=	${crate}/.cargo-checksum.json
.endfor
.for from to in ${CKSUMS}
SUBST_SED.cksum+=	-e 's,${from},${to},g'
.endfor

post-extract:
	set -e;									\
	if ${TEST} -e ${WRKDIR}/rust-${RUST_STAGE0_VER}-${RUST_ARCH}/install.sh	\
	  -a ! -e ${RUST_BOOTSTRAP_PATH}/bin/rustc; then \
		cd ${WRKDIR}/rust-${RUST_STAGE0_VER}-${RUST_ARCH};	\
		env ${MAKE_ENV} ${TOOLS_BASH} \
			./install.sh --prefix=${RUST_BOOTSTRAP_PATH};	\
		cd ${WRKDIR}/rust-std-${RUST_STAGE0_VER}-${RUST_ARCH};	\
		env ${MAKE_ENV} ${TOOLS_BASH} \
			./install.sh --prefix=${RUST_BOOTSTRAP_PATH};	\
	fi
	SDIR=${WRKDIR}/scripts; \
	${MKDIR} $${SDIR}; \
	cd $${SDIR}; \
	${RM} -f c++-wrap; \
	${RM} -f clang++-wrap; \
	${RM} -f clang-wrap; \
	${RM} -f ar-wrap; \
	${CP} ${.CURDIR}/files/gcc-wrap .; \
	${CHMOD} +x gcc-wrap; \
	${LN} -s gcc-wrap c++-wrap; \
	${LN} -s gcc-wrap clang++-wrap; \
	${LN} -s gcc-wrap clang-wrap; \
	${LN} -s gcc-wrap ar-wrap

# Rust builds some bundled components with strict version requirements, ensure
# that any conflicting packages pulled in via dependencies are not buildlinked.
BUILDLINK_FILES_CMD.xz=		${TRUE}
MAKE_ENV+=			LZMA_API_STATIC=1
pre-configure:
	${RM} -rf ${BUILDLINK_DIR}/include/libssh2*

# These are essentially copies of the "all", "test", and "install" Makefile
# targets, but are duplicated here so that we can specify -j.
do-build:
	${RUN}${_ULIMIT_CMD}						\
	cd ${WRKSRC} &&							\
	${SETENV} ${MAKE_ENV}						\
	sh -c "if [ \"${BUILD_TARGET}\" = \"dist\" ]; then		\
		unset DESTDIR;						\
		${TOOL_PYTHONBIN} ./x.py				\
		    ${BUILD_TARGET} -j ${_MAKE_JOBS_N};			\
	else								\
		${TOOL_PYTHONBIN} ./x.py				\
		    ${BUILD_TARGET} --stage 2 -j ${_MAKE_JOBS_N} &&	\
		${TOOL_PYTHONBIN} ./x.py				\
		    doc --stage 2 -j ${_MAKE_JOBS_N};			\
	fi"

do-test:
	${RUN}${_ULIMIT_CMD}						\
	cd ${WRKSRC} &&							\
	${SETENV} ${MAKE_ENV}						\
		${TOOL_PYTHONBIN} ./x.py test -j ${_MAKE_JOBS_N}

do-install:
	${RUN}${_ULIMIT_CMD}						\
	cd ${WRKSRC} &&							\
	${SETENV} ${MAKE_ENV} ${INSTALL_ENV} 				\
		${TOOL_PYTHONBIN} ./x.py install -j ${_MAKE_JOBS_N}

SUBST_CLASSES+=		destdir
SUBST_STAGE.destdir=	post-install
SUBST_FILES.destdir=	${DESTDIR}${PREFIX}/lib/rustlib/manifest-*
SUBST_SED.destdir=	-e 's|file:${DESTDIR}${PREFIX}|file:${PREFIX}|'

GENERATE_PLIST+=	${FIND} ${DESTDIR}${PREFIX} \( -type f -o -type l \) -print | \
			${SED} -e 's,${DESTDIR}${PREFIX}/,,' | ${SORT} ;

# Create a relocatable stage2 bootstrap from the bits we just built.
# This target is a developer tool and remains in place for convenience.
#BOOTSTRAP_NAME=	${PKGNAME_NOREV:C/rust/rust-nightly/}-${RUST_ARCH}
BOOTSTRAP_NAME=		${PKGNAME_NOREV}-${RUST_ARCH}
BOOTSTRAP_TMPDIR=	${WRKDIR}/${BOOTSTRAP_NAME}
USE_TOOLS+=		gtar

.PHONY: stage0-bootstrap
stage0-bootstrap: install
	${RM} -rf ${BOOTSTRAP_TMPDIR}
	${MKDIR} ${BOOTSTRAP_TMPDIR}
	(cd ${BOOTSTRAP_TMPDIR}; \
	DISTDIR=${WRKSRC}/bild/dist; \
	VER_ARCH=${PKGVERSION}-${RUST_ARCH}; \
	RUSTC=rustc-$${VER_ARCH}; \
	RUSTC_FILE=$${RUSTC}.tar.gz; \
	RUST_STD=rust-std-$${VER_ARCH}; \
	RUST_STD_FILE=$${RUST_STD}.tar.gz; \
	${GTAR} -xzf $${DISTDIR}/$${RUSTC_FILE}; \
		(cd ${RUSTC}; \
	RPATH='/usr/pkg/lib:/lib:/usr/lib:$$ORIGIN/../lib'; \
	for f in rls-preview/bin/rls rustc/bin/rustc rustc/bin/rustdoc; do \
		chrpath -r $$RPATH $$f; \
	done; \
	RPATH='/usr/pkg/lib:/lib:/usr/lib:$$ORIGIN'; \
	for f in rustc/lib/*.so*; do \
		chrpath -r $$RPATH $$f; \
	done; \
	RPATH='/usr/pkg/lib:/lib:/usr/lib:$$ORIGIN:$$ORIGIN/../../..'; \
	for f in rustc/lib/rustlib/*/*/*.so*; do \
		chrpath -r $$RPATH $$f; \
	done;); \
	${GTAR} -czf $${RUSTC_FILE} $${RUSTC}; \
	${CP} $${DISTDIR}/$${RUST_STD_FILE} .; \
	${ECHO} "Fixed stage0 bootstrap in ${BOOTSTRAP_TMPDIR}:"; \
	${ECHO} "$${RUSTC_FILE}"; \
	${ECHO} "$${RUST_STD_FILE}"; \
	)

.include "options.mk"

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
