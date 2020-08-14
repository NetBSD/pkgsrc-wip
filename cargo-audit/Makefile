# $NetBSD$

GITHUB_PROJECT=	cargo-audit
DISTNAME=	v0.7.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	devel security
MASTER_SITES=	${MASTER_SITE_GITHUB:=RustSec/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://github.com/RustSec/cargo-audit/
COMMENT=	Audit Cargo.lock files for crates with security vulnerabilities
LICENSE=	apache-2.0 # or MIT

WRKSRC=			${WRKDIR}/cargo-audit-0.7.0
CARGO_CRATE_DEPENDS+=	assert_cmd-0.11.1
CARGO_CRATE_DEPENDS+=	autocfg-0.1.4
CARGO_CRATE_DEPENDS+=	backtrace-0.3.32
CARGO_CRATE_DEPENDS+=	backtrace-sys-0.1.30
CARGO_CRATE_DEPENDS+=	bitflags-1.1.0
CARGO_CRATE_DEPENDS+=	c2-chacha-0.2.2
CARGO_CRATE_DEPENDS+=	cc-1.0.37
CARGO_CRATE_DEPENDS+=	cfg-if-0.1.9
CARGO_CRATE_DEPENDS+=	chrono-0.4.7
CARGO_CRATE_DEPENDS+=	curl-sys-0.4.20
CARGO_CRATE_DEPENDS+=	difference-2.0.0
CARGO_CRATE_DEPENDS+=	directories-1.0.2
CARGO_CRATE_DEPENDS+=	escargot-0.4.0
CARGO_CRATE_DEPENDS+=	failure-0.1.5
CARGO_CRATE_DEPENDS+=	failure_derive-0.1.5
CARGO_CRATE_DEPENDS+=	getrandom-0.1.6
CARGO_CRATE_DEPENDS+=	git2-0.8.0
CARGO_CRATE_DEPENDS+=	gumdrop-0.6.0
CARGO_CRATE_DEPENDS+=	gumdrop_derive-0.6.0
CARGO_CRATE_DEPENDS+=	idna-0.1.5
CARGO_CRATE_DEPENDS+=	itoa-0.4.4
CARGO_CRATE_DEPENDS+=	lazy_static-1.3.0
CARGO_CRATE_DEPENDS+=	libc-0.2.60
CARGO_CRATE_DEPENDS+=	libgit2-sys-0.7.11
CARGO_CRATE_DEPENDS+=	libssh2-sys-0.2.11
CARGO_CRATE_DEPENDS+=	libz-sys-1.0.25
CARGO_CRATE_DEPENDS+=	log-0.4.7
CARGO_CRATE_DEPENDS+=	matches-0.1.8
CARGO_CRATE_DEPENDS+=	num-integer-0.1.41
CARGO_CRATE_DEPENDS+=	num-traits-0.2.8
CARGO_CRATE_DEPENDS+=	openssl-probe-0.1.2
CARGO_CRATE_DEPENDS+=	openssl-sys-0.9.47
CARGO_CRATE_DEPENDS+=	percent-encoding-1.0.1
CARGO_CRATE_DEPENDS+=	pkg-config-0.3.14
CARGO_CRATE_DEPENDS+=	platforms-0.2.0
CARGO_CRATE_DEPENDS+=	ppv-lite86-0.2.5
CARGO_CRATE_DEPENDS+=	predicates-1.0.1
CARGO_CRATE_DEPENDS+=	predicates-core-1.0.0
CARGO_CRATE_DEPENDS+=	predicates-tree-1.0.0
CARGO_CRATE_DEPENDS+=	proc-macro2-0.4.30
CARGO_CRATE_DEPENDS+=	quote-0.6.13
CARGO_CRATE_DEPENDS+=	rand-0.7.0
CARGO_CRATE_DEPENDS+=	rand_chacha-0.2.0
CARGO_CRATE_DEPENDS+=	rand_core-0.5.0
CARGO_CRATE_DEPENDS+=	rand_hc-0.2.0
CARGO_CRATE_DEPENDS+=	redox_syscall-0.1.56
CARGO_CRATE_DEPENDS+=	remove_dir_all-0.5.2
CARGO_CRATE_DEPENDS+=	rustc-demangle-0.1.15
CARGO_CRATE_DEPENDS+=	rustsec-0.12.0
CARGO_CRATE_DEPENDS+=	ryu-1.0.0
CARGO_CRATE_DEPENDS+=	semver-0.9.0
CARGO_CRATE_DEPENDS+=	semver-parser-0.7.0
CARGO_CRATE_DEPENDS+=	serde-1.0.94
CARGO_CRATE_DEPENDS+=	serde_derive-1.0.94
CARGO_CRATE_DEPENDS+=	serde_json-1.0.40
CARGO_CRATE_DEPENDS+=	serial_test-0.2.0
CARGO_CRATE_DEPENDS+=	serial_test_derive-0.2.0
CARGO_CRATE_DEPENDS+=	smallvec-0.6.10
CARGO_CRATE_DEPENDS+=	spin-0.5.0
CARGO_CRATE_DEPENDS+=	syn-0.15.39
CARGO_CRATE_DEPENDS+=	synstructure-0.10.2
CARGO_CRATE_DEPENDS+=	tempfile-3.1.0
CARGO_CRATE_DEPENDS+=	termcolor-1.0.5
CARGO_CRATE_DEPENDS+=	time-0.1.42
CARGO_CRATE_DEPENDS+=	toml-0.5.1
CARGO_CRATE_DEPENDS+=	treeline-0.1.0
CARGO_CRATE_DEPENDS+=	unicode-bidi-0.3.4
CARGO_CRATE_DEPENDS+=	unicode-normalization-0.1.8
CARGO_CRATE_DEPENDS+=	unicode-xid-0.1.0
CARGO_CRATE_DEPENDS+=	url-1.7.2
CARGO_CRATE_DEPENDS+=	vcpkg-0.2.7
CARGO_CRATE_DEPENDS+=	winapi-0.3.7
CARGO_CRATE_DEPENDS+=	winapi-i686-pc-windows-gnu-0.4.0
CARGO_CRATE_DEPENDS+=	winapi-util-0.1.2
CARGO_CRATE_DEPENDS+=	winapi-x86_64-pc-windows-gnu-0.4.0
CARGO_CRATE_DEPENDS+=	wincolor-1.0.1
USE_LANGUAGES=		c

INSTALLATION_DIRS=	bin

MAKE_ENV+=		OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cargo-audit ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../lang/rust/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
