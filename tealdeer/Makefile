# $NetBSD$

DISTNAME=	tealdeer-1.1.0
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	sysutils wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=dbrgn/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/dbrgn/tealdeer/
COMMENT=	Simplified, example based and community-driven man pages
LICENSE=	mit OR apache-2.0

USE_LANGUAGES=	c # rust

CARGO_CRATE_DEPENDS+=	adler32-1.0.3
CARGO_CRATE_DEPENDS+=	aho-corasick-0.6.8
CARGO_CRATE_DEPENDS+=	ansi_term-0.10.2
CARGO_CRATE_DEPENDS+=	assert_cli-0.5.4
CARGO_CRATE_DEPENDS+=	atty-0.2.11
CARGO_CRATE_DEPENDS+=	backtrace-0.3.9
CARGO_CRATE_DEPENDS+=	backtrace-sys-0.1.24
CARGO_CRATE_DEPENDS+=	bitflags-0.9.1
CARGO_CRATE_DEPENDS+=	bitflags-1.0.4
CARGO_CRATE_DEPENDS+=	build_const-0.2.1
CARGO_CRATE_DEPENDS+=	bytecount-0.3.2
CARGO_CRATE_DEPENDS+=	cargo_metadata-0.2.3
CARGO_CRATE_DEPENDS+=	cargo_metadata-0.5.8
CARGO_CRATE_DEPENDS+=	cc-1.0.25
CARGO_CRATE_DEPENDS+=	cfg-if-0.1.6
CARGO_CRATE_DEPENDS+=	clippy-0.0.174
CARGO_CRATE_DEPENDS+=	clippy_lints-0.0.174
CARGO_CRATE_DEPENDS+=	colored-1.6.1
CARGO_CRATE_DEPENDS+=	crc-1.8.1
CARGO_CRATE_DEPENDS+=	curl-0.4.18
CARGO_CRATE_DEPENDS+=	curl-sys-0.4.13
CARGO_CRATE_DEPENDS+=	difference-1.0.0
CARGO_CRATE_DEPENDS+=	docopt-0.8.3
CARGO_CRATE_DEPENDS+=	either-1.5.0
CARGO_CRATE_DEPENDS+=	env_logger-0.5.13
CARGO_CRATE_DEPENDS+=	environment-0.1.1
CARGO_CRATE_DEPENDS+=	error-chain-0.11.0
CARGO_CRATE_DEPENDS+=	filetime-0.2.1
CARGO_CRATE_DEPENDS+=	flate2-1.0.4
CARGO_CRATE_DEPENDS+=	fuchsia-zircon-0.3.3
CARGO_CRATE_DEPENDS+=	fuchsia-zircon-sys-0.3.3
CARGO_CRATE_DEPENDS+=	getopts-0.2.18
CARGO_CRATE_DEPENDS+=	glob-0.2.11
CARGO_CRATE_DEPENDS+=	humantime-1.1.1
CARGO_CRATE_DEPENDS+=	idna-0.1.5
CARGO_CRATE_DEPENDS+=	if_chain-0.1.3
CARGO_CRATE_DEPENDS+=	itertools-0.6.5
CARGO_CRATE_DEPENDS+=	itoa-0.4.3
CARGO_CRATE_DEPENDS+=	kernel32-sys-0.2.2
CARGO_CRATE_DEPENDS+=	lazy_static-0.2.11
CARGO_CRATE_DEPENDS+=	lazy_static-1.1.0
CARGO_CRATE_DEPENDS+=	libc-0.2.43
CARGO_CRATE_DEPENDS+=	libz-sys-1.0.24
CARGO_CRATE_DEPENDS+=	log-0.4.5
CARGO_CRATE_DEPENDS+=	matches-0.1.8
CARGO_CRATE_DEPENDS+=	memchr-2.1.0
CARGO_CRATE_DEPENDS+=	miniz-sys-0.1.11
CARGO_CRATE_DEPENDS+=	miniz_oxide-0.2.0
CARGO_CRATE_DEPENDS+=	miniz_oxide_c_api-0.2.0
CARGO_CRATE_DEPENDS+=	openssl-probe-0.1.2
CARGO_CRATE_DEPENDS+=	openssl-sys-0.9.39
CARGO_CRATE_DEPENDS+=	percent-encoding-1.0.1
CARGO_CRATE_DEPENDS+=	pkg-config-0.3.14
CARGO_CRATE_DEPENDS+=	proc-macro2-0.4.20
CARGO_CRATE_DEPENDS+=	pulldown-cmark-0.0.15
CARGO_CRATE_DEPENDS+=	pulldown-cmark-0.1.2
CARGO_CRATE_DEPENDS+=	quick-error-1.2.2
CARGO_CRATE_DEPENDS+=	quine-mc_cluskey-0.2.4
CARGO_CRATE_DEPENDS+=	quote-0.6.8
CARGO_CRATE_DEPENDS+=	rand-0.4.3
CARGO_CRATE_DEPENDS+=	redox_syscall-0.1.40
CARGO_CRATE_DEPENDS+=	redox_termios-0.1.1
CARGO_CRATE_DEPENDS+=	regex-0.2.11
CARGO_CRATE_DEPENDS+=	regex-1.0.5
CARGO_CRATE_DEPENDS+=	regex-syntax-0.4.2
CARGO_CRATE_DEPENDS+=	regex-syntax-0.5.6
CARGO_CRATE_DEPENDS+=	regex-syntax-0.6.2
CARGO_CRATE_DEPENDS+=	remove_dir_all-0.5.1
CARGO_CRATE_DEPENDS+=	rustc-demangle-0.1.9
CARGO_CRATE_DEPENDS+=	ryu-0.2.6
CARGO_CRATE_DEPENDS+=	same-file-1.0.3
CARGO_CRATE_DEPENDS+=	schannel-0.1.14
CARGO_CRATE_DEPENDS+=	semver-0.6.0
CARGO_CRATE_DEPENDS+=	semver-0.9.0
CARGO_CRATE_DEPENDS+=	semver-parser-0.7.0
CARGO_CRATE_DEPENDS+=	serde-1.0.80
CARGO_CRATE_DEPENDS+=	serde_derive-1.0.80
CARGO_CRATE_DEPENDS+=	serde_json-1.0.32
CARGO_CRATE_DEPENDS+=	skeptic-0.13.3
CARGO_CRATE_DEPENDS+=	socket2-0.3.8
CARGO_CRATE_DEPENDS+=	strsim-0.6.0
CARGO_CRATE_DEPENDS+=	syn-0.15.13
CARGO_CRATE_DEPENDS+=	tar-0.4.17
CARGO_CRATE_DEPENDS+=	tempdir-0.3.7
CARGO_CRATE_DEPENDS+=	termcolor-1.0.4
CARGO_CRATE_DEPENDS+=	termion-1.5.1
CARGO_CRATE_DEPENDS+=	thread_local-0.3.6
CARGO_CRATE_DEPENDS+=	time-0.1.40
CARGO_CRATE_DEPENDS+=	toml-0.4.8
CARGO_CRATE_DEPENDS+=	ucd-util-0.1.1
CARGO_CRATE_DEPENDS+=	unicode-bidi-0.3.4
CARGO_CRATE_DEPENDS+=	unicode-normalization-0.1.7
CARGO_CRATE_DEPENDS+=	unicode-width-0.1.5
CARGO_CRATE_DEPENDS+=	unicode-xid-0.1.0
CARGO_CRATE_DEPENDS+=	url-1.7.1
CARGO_CRATE_DEPENDS+=	utf8-ranges-1.0.1
CARGO_CRATE_DEPENDS+=	utime-0.2.1
CARGO_CRATE_DEPENDS+=	vcpkg-0.2.6
CARGO_CRATE_DEPENDS+=	version_check-0.1.5
CARGO_CRATE_DEPENDS+=	walkdir-2.2.5
CARGO_CRATE_DEPENDS+=	winapi-0.2.8
CARGO_CRATE_DEPENDS+=	winapi-0.3.6
CARGO_CRATE_DEPENDS+=	winapi-build-0.1.1
CARGO_CRATE_DEPENDS+=	winapi-i686-pc-windows-gnu-0.4.0
CARGO_CRATE_DEPENDS+=	winapi-util-0.1.1
CARGO_CRATE_DEPENDS+=	winapi-x86_64-pc-windows-gnu-0.4.0
CARGO_CRATE_DEPENDS+=	wincolor-1.0.1
CARGO_CRATE_DEPENDS+=	xattr-0.2.2
CARGO_CRATE_DEPENDS+=	xdg-2.1.0

MAKE_ENV+=		OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}

INSTALLATION_DIRS=	bin share/bash-completion/completions

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/cargo build --locked --frozen --release -j${_MAKE_JOBS_N}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/tldr ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/bash_tealdeer ${DESTDIR}${PREFIX}/share/bash-completion/completions/tldr

.include "../../lang/rust/cargo.mk"
.include "../../lang/rust/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
