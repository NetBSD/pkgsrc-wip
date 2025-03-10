# $NetBSD$

GITHUB_PROJECT=	IRust
GITHUB_TAG=	refs/tags/irust@1.71.29
DISTNAME=	irust
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=sigmaSd/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sigmaSd/IRust/
COMMENT=	Cross Platform Rust Repl
LICENSE=	mit

CARGO_INSTALL_ARGS?=	install --path crates/irust --root ${DESTDIR}${PREFIX} ${DEFAULT_CARGO_ARGS}

WRKSRC=			${WRKDIR}/IRust-irust-1.71.29
CARGO_CRATE_DEPENDS+=	autocfg-1.1.0
CARGO_CRATE_DEPENDS+=	bincode-1.3.3
CARGO_CRATE_DEPENDS+=	bitflags-1.3.2
CARGO_CRATE_DEPENDS+=	bitflags-2.5.0
CARGO_CRATE_DEPENDS+=	cfg-if-1.0.0
CARGO_CRATE_DEPENDS+=	crossterm-0.27.0
CARGO_CRATE_DEPENDS+=	crossterm_winapi-0.9.1
CARGO_CRATE_DEPENDS+=	dirs-5.0.1
CARGO_CRATE_DEPENDS+=	dirs-sys-0.4.1
CARGO_CRATE_DEPENDS+=	equivalent-1.0.1
CARGO_CRATE_DEPENDS+=	filedescriptor-0.8.2
CARGO_CRATE_DEPENDS+=	getrandom-0.2.12
CARGO_CRATE_DEPENDS+=	hashbrown-0.14.3
CARGO_CRATE_DEPENDS+=	indexmap-2.2.6
CARGO_CRATE_DEPENDS+=	itoa-1.0.10
CARGO_CRATE_DEPENDS+=	libc-0.2.155
CARGO_CRATE_DEPENDS+=	libloading-0.7.4
CARGO_CRATE_DEPENDS+=	libredox-0.0.1
CARGO_CRATE_DEPENDS+=	lock_api-0.4.11
CARGO_CRATE_DEPENDS+=	log-0.4.21
CARGO_CRATE_DEPENDS+=	memchr-2.7.1
CARGO_CRATE_DEPENDS+=	mio-0.8.11
CARGO_CRATE_DEPENDS+=	option-ext-0.2.0
CARGO_CRATE_DEPENDS+=	parking_lot-0.12.1
CARGO_CRATE_DEPENDS+=	parking_lot_core-0.9.9
CARGO_CRATE_DEPENDS+=	proc-macro2-1.0.79
CARGO_CRATE_DEPENDS+=	quote-1.0.35
CARGO_CRATE_DEPENDS+=	redox_syscall-0.4.1
CARGO_CRATE_DEPENDS+=	redox_users-0.4.4
CARGO_CRATE_DEPENDS+=	rscript-0.17.0
CARGO_CRATE_DEPENDS+=	rustc-ap-rustc_lexer-727.0.0
CARGO_CRATE_DEPENDS+=	ryu-1.0.17
CARGO_CRATE_DEPENDS+=	scopeguard-1.2.0
CARGO_CRATE_DEPENDS+=	semver-1.0.22
CARGO_CRATE_DEPENDS+=	serde-1.0.197
CARGO_CRATE_DEPENDS+=	serde_derive-1.0.197
CARGO_CRATE_DEPENDS+=	serde_json-1.0.114
CARGO_CRATE_DEPENDS+=	serde_spanned-0.6.5
CARGO_CRATE_DEPENDS+=	signal-hook-0.3.17
CARGO_CRATE_DEPENDS+=	signal-hook-mio-0.2.3
CARGO_CRATE_DEPENDS+=	signal-hook-registry-1.4.1
CARGO_CRATE_DEPENDS+=	smallvec-1.13.2
CARGO_CRATE_DEPENDS+=	syn-2.0.55
CARGO_CRATE_DEPENDS+=	thiserror-1.0.58
CARGO_CRATE_DEPENDS+=	thiserror-impl-1.0.58
CARGO_CRATE_DEPENDS+=	toml-0.7.8
CARGO_CRATE_DEPENDS+=	toml_datetime-0.6.5
CARGO_CRATE_DEPENDS+=	toml_edit-0.19.15
CARGO_CRATE_DEPENDS+=	unicode-ident-1.0.12
CARGO_CRATE_DEPENDS+=	unicode-width-0.1.11
CARGO_CRATE_DEPENDS+=	unicode-xid-0.2.4
CARGO_CRATE_DEPENDS+=	uuid-1.8.0
CARGO_CRATE_DEPENDS+=	wasi-0.11.0+wasi-snapshot-preview1
CARGO_CRATE_DEPENDS+=	winapi-0.3.9
CARGO_CRATE_DEPENDS+=	winapi-i686-pc-windows-gnu-0.4.0
CARGO_CRATE_DEPENDS+=	winapi-x86_64-pc-windows-gnu-0.4.0
CARGO_CRATE_DEPENDS+=	windows-sys-0.48.0
CARGO_CRATE_DEPENDS+=	windows-targets-0.48.5
CARGO_CRATE_DEPENDS+=	windows_aarch64_gnullvm-0.48.5
CARGO_CRATE_DEPENDS+=	windows_aarch64_msvc-0.48.5
CARGO_CRATE_DEPENDS+=	windows_i686_gnu-0.48.5
CARGO_CRATE_DEPENDS+=	windows_i686_msvc-0.48.5
CARGO_CRATE_DEPENDS+=	windows_x86_64_gnu-0.48.5
CARGO_CRATE_DEPENDS+=	windows_x86_64_gnullvm-0.48.5
CARGO_CRATE_DEPENDS+=	windows_x86_64_msvc-0.48.5
CARGO_CRATE_DEPENDS+=	winnow-0.5.40
USE_LANGUAGES=		c

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
