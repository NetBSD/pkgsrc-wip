# $NetBSD$

DISTNAME=	pack-0.2.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=maralla/}
GITHUB_TAG=	v0.2.5

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://github.com/maralla/pack
COMMENT=	Vim package manager
LICENSE=	mit

CARGO_CRATE_DEPENDS+=	ansi_term-0.9.0
CARGO_CRATE_DEPENDS+=	arc-swap-0.4.4
CARGO_CRATE_DEPENDS+=	argon2rs-0.2.5
CARGO_CRATE_DEPENDS+=	arrayvec-0.4.10
CARGO_CRATE_DEPENDS+=	atty-0.2.6
CARGO_CRATE_DEPENDS+=	autocfg-0.1.7
CARGO_CRATE_DEPENDS+=	backtrace-0.3.11
CARGO_CRATE_DEPENDS+=	backtrace-sys-0.1.28
CARGO_CRATE_DEPENDS+=	bitflags-0.9.1
CARGO_CRATE_DEPENDS+=	bitflags-1.2.1
CARGO_CRATE_DEPENDS+=	blake2-rfc-0.2.18
CARGO_CRATE_DEPENDS+=	cc-1.0.48
CARGO_CRATE_DEPENDS+=	cfg-if-0.1.6
CARGO_CRATE_DEPENDS+=	clap-2.27.1
CARGO_CRATE_DEPENDS+=	cloudabi-0.0.3
CARGO_CRATE_DEPENDS+=	constant_time_eq-0.1.3
CARGO_CRATE_DEPENDS+=	crossbeam-channel-0.4.0
CARGO_CRATE_DEPENDS+=	crossbeam-utils-0.7.0
CARGO_CRATE_DEPENDS+=	dirs-1.0.5
CARGO_CRATE_DEPENDS+=	failure-0.1.5
CARGO_CRATE_DEPENDS+=	failure_derive-0.1.5
CARGO_CRATE_DEPENDS+=	fuchsia-cprng-0.1.1
CARGO_CRATE_DEPENDS+=	getrandom-0.1.13
CARGO_CRATE_DEPENDS+=	git2-0.10.2
CARGO_CRATE_DEPENDS+=	hermit-abi-0.1.5
CARGO_CRATE_DEPENDS+=	idna-0.2.0
CARGO_CRATE_DEPENDS+=	jobserver-0.1.17
CARGO_CRATE_DEPENDS+=	kernel32-sys-0.2.2
CARGO_CRATE_DEPENDS+=	lazy_static-1.4.0
CARGO_CRATE_DEPENDS+=	libc-0.2.66
CARGO_CRATE_DEPENDS+=	libgit2-sys-0.9.2
CARGO_CRATE_DEPENDS+=	libssh2-sys-0.2.11
CARGO_CRATE_DEPENDS+=	libz-sys-1.0.24
CARGO_CRATE_DEPENDS+=	log-0.4.8
CARGO_CRATE_DEPENDS+=	matches-0.1.6
CARGO_CRATE_DEPENDS+=	nodrop-0.1.13
CARGO_CRATE_DEPENDS+=	num_cpus-1.11.1
CARGO_CRATE_DEPENDS+=	openssl-probe-0.1.2
CARGO_CRATE_DEPENDS+=	openssl-sys-0.9.39
CARGO_CRATE_DEPENDS+=	percent-encoding-2.1.0
CARGO_CRATE_DEPENDS+=	pkg-config-0.3.14
CARGO_CRATE_DEPENDS+=	proc-macro2-0.4.30
CARGO_CRATE_DEPENDS+=	quote-0.6.12
CARGO_CRATE_DEPENDS+=	rand_core-0.3.1
CARGO_CRATE_DEPENDS+=	rand_core-0.4.0
CARGO_CRATE_DEPENDS+=	rand_os-0.1.3
CARGO_CRATE_DEPENDS+=	rdrand-0.4.0
CARGO_CRATE_DEPENDS+=	redox_syscall-0.1.37
CARGO_CRATE_DEPENDS+=	redox_termios-0.1.1
CARGO_CRATE_DEPENDS+=	redox_users-0.3.0
CARGO_CRATE_DEPENDS+=	rustc-demangle-0.1.14
CARGO_CRATE_DEPENDS+=	same-file-0.1.3
CARGO_CRATE_DEPENDS+=	scoped_threadpool-0.1.9
CARGO_CRATE_DEPENDS+=	signal-hook-0.1.12
CARGO_CRATE_DEPENDS+=	signal-hook-registry-1.2.0
CARGO_CRATE_DEPENDS+=	simple-logging-2.0.2
CARGO_CRATE_DEPENDS+=	strsim-0.6.0
CARGO_CRATE_DEPENDS+=	syn-0.15.34
CARGO_CRATE_DEPENDS+=	synstructure-0.10.2
CARGO_CRATE_DEPENDS+=	termion-1.5.1
CARGO_CRATE_DEPENDS+=	textwrap-0.9.0
CARGO_CRATE_DEPENDS+=	thread-id-3.3.0
CARGO_CRATE_DEPENDS+=	unicode-bidi-0.3.4
CARGO_CRATE_DEPENDS+=	unicode-normalization-0.1.5
CARGO_CRATE_DEPENDS+=	unicode-width-0.1.4
CARGO_CRATE_DEPENDS+=	unicode-xid-0.1.0
CARGO_CRATE_DEPENDS+=	url-2.1.0
CARGO_CRATE_DEPENDS+=	vcpkg-0.2.2
CARGO_CRATE_DEPENDS+=	vec_map-0.8.0
CARGO_CRATE_DEPENDS+=	walkdir-1.0.7
CARGO_CRATE_DEPENDS+=	wasi-0.7.0
CARGO_CRATE_DEPENDS+=	winapi-0.2.8
CARGO_CRATE_DEPENDS+=	winapi-0.3.4
CARGO_CRATE_DEPENDS+=	winapi-build-0.1.1
CARGO_CRATE_DEPENDS+=	winapi-i686-pc-windows-gnu-0.4.0
CARGO_CRATE_DEPENDS+=	winapi-x86_64-pc-windows-gnu-0.4.0
CARGO_CRATE_DEPENDS+=	yaml-rust-0.3.5

INSTALLATION_DIRS=	bin

MAKE_ENV+=		OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/pack ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../lang/rust/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
