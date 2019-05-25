# $NetBSD$

DISTNAME=	exa
PKGNAME=	${DISTNAME}-0.8.0-20190525 # 0.9.0-pre
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=ogham/}
GITHUB_PROJECT=	exa
GITHUB_TAG=	35bf32abb9b8b445127c4722f45dcda25a55075a
DIST_SUBDIR=	${GITHUB_PROJECT}
EXTRACT_USING=	bsdtar

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://the.exa.website/
COMMENT=	Replacement for ls(1) written in Rust
LICENSE=	mit

USE_LANGUAGES=	c

CARGO_CRATE_DEPENDS+=	aho-corasick-0.6.9
CARGO_CRATE_DEPENDS+=	ansi_term-0.11.0
CARGO_CRATE_DEPENDS+=	atty-0.2.10
CARGO_CRATE_DEPENDS+=	bitflags-0.9.1
CARGO_CRATE_DEPENDS+=	bitflags-1.0.1
CARGO_CRATE_DEPENDS+=	byteorder-0.4.2
CARGO_CRATE_DEPENDS+=	cc-1.0.37
CARGO_CRATE_DEPENDS+=	cfg-if-0.1.6
CARGO_CRATE_DEPENDS+=	cmake-0.1.25
CARGO_CRATE_DEPENDS+=	conv-0.3.3
CARGO_CRATE_DEPENDS+=	custom_derive-0.1.7
CARGO_CRATE_DEPENDS+=	datetime-0.4.7
CARGO_CRATE_DEPENDS+=	env_logger-0.6.0
CARGO_CRATE_DEPENDS+=	gcc-0.3.53
CARGO_CRATE_DEPENDS+=	getopts-0.2.14
CARGO_CRATE_DEPENDS+=	git2-0.7.5
CARGO_CRATE_DEPENDS+=	glob-0.2.11
CARGO_CRATE_DEPENDS+=	humantime-1.1.1
CARGO_CRATE_DEPENDS+=	idna-0.1.4
CARGO_CRATE_DEPENDS+=	iso8601-0.1.1
CARGO_CRATE_DEPENDS+=	kernel32-sys-0.2.2
CARGO_CRATE_DEPENDS+=	lazy_static-1.0.0
CARGO_CRATE_DEPENDS+=	libc-0.2.43
CARGO_CRATE_DEPENDS+=	libc-0.2.50
CARGO_CRATE_DEPENDS+=	libgit2-sys-0.7.11
CARGO_CRATE_DEPENDS+=	libz-sys-1.0.25
CARGO_CRATE_DEPENDS+=	locale-0.2.2
CARGO_CRATE_DEPENDS+=	log-0.4.1
CARGO_CRATE_DEPENDS+=	magenta-0.1.1
CARGO_CRATE_DEPENDS+=	magenta-sys-0.1.1
CARGO_CRATE_DEPENDS+=	matches-0.1.6
CARGO_CRATE_DEPENDS+=	memchr-2.1.2
CARGO_CRATE_DEPENDS+=	natord-1.0.9
CARGO_CRATE_DEPENDS+=	nom-1.2.4
CARGO_CRATE_DEPENDS+=	num-0.1.40
CARGO_CRATE_DEPENDS+=	num-bigint-0.1.40
CARGO_CRATE_DEPENDS+=	num-complex-0.1.40
CARGO_CRATE_DEPENDS+=	num_cpus-1.8.0
CARGO_CRATE_DEPENDS+=	num-integer-0.1.35
CARGO_CRATE_DEPENDS+=	num-iter-0.1.34
CARGO_CRATE_DEPENDS+=	num-rational-0.1.39
CARGO_CRATE_DEPENDS+=	num-traits-0.1.43
CARGO_CRATE_DEPENDS+=	num-traits-0.2.1
CARGO_CRATE_DEPENDS+=	number_prefix-0.2.8
CARGO_CRATE_DEPENDS+=	pad-0.1.5
CARGO_CRATE_DEPENDS+=	percent-encoding-1.0.1
CARGO_CRATE_DEPENDS+=	pkg-config-0.3.9
CARGO_CRATE_DEPENDS+=	quick-error-1.2.1
CARGO_CRATE_DEPENDS+=	rand-0.3.16
CARGO_CRATE_DEPENDS+=	redox_syscall-0.1.37
CARGO_CRATE_DEPENDS+=	redox_termios-0.1.1
CARGO_CRATE_DEPENDS+=	regex-1.1.0
CARGO_CRATE_DEPENDS+=	regex-syntax-0.6.4
CARGO_CRATE_DEPENDS+=	rustc-serialize-0.3.24
CARGO_CRATE_DEPENDS+=	scoped_threadpool-0.1.9
CARGO_CRATE_DEPENDS+=	termcolor-1.0.4
CARGO_CRATE_DEPENDS+=	termion-1.5.1
CARGO_CRATE_DEPENDS+=	term_grid-0.1.7
CARGO_CRATE_DEPENDS+=	term_size-0.3.1
CARGO_CRATE_DEPENDS+=	thread-id-2.0.0
CARGO_CRATE_DEPENDS+=	thread_local-0.3.6
CARGO_CRATE_DEPENDS+=	ucd-util-0.1.1
CARGO_CRATE_DEPENDS+=	unicode-bidi-0.3.4
CARGO_CRATE_DEPENDS+=	unicode-normalization-0.1.5
CARGO_CRATE_DEPENDS+=	unicode-width-0.1.4
CARGO_CRATE_DEPENDS+=	url-1.7.0
CARGO_CRATE_DEPENDS+=	users-0.8.1
CARGO_CRATE_DEPENDS+=	users-0.9.1
CARGO_CRATE_DEPENDS+=	utf8-ranges-1.0.2
CARGO_CRATE_DEPENDS+=	vcpkg-0.2.2
CARGO_CRATE_DEPENDS+=	version_check-0.1.5
CARGO_CRATE_DEPENDS+=	winapi-0.2.8
CARGO_CRATE_DEPENDS+=	winapi-0.3.4
CARGO_CRATE_DEPENDS+=	winapi-build-0.1.1
CARGO_CRATE_DEPENDS+=	winapi-i686-pc-windows-gnu-0.4.0
CARGO_CRATE_DEPENDS+=	winapi-util-0.1.1
CARGO_CRATE_DEPENDS+=	winapi-x86_64-pc-windows-gnu-0.4.0
CARGO_CRATE_DEPENDS+=	wincolor-1.0.1
CARGO_CRATE_DEPENDS+=	zoneinfo_compiled-0.4.7

INSTALLATION_DIRS=	bin \
			${PKGMANDIR}/man1

EGDIR=			${PREFIX}/share/examples/exa

CONF_FILES+=		${EGDIR}/completions.bash \
			${PKG_SYSCONFDIR}/bash_completion.d/exa.bash
CONF_FILES+=		${EGDIR}/completions.fish \
			${PREFIX}/share/fish/completions/exa.fish
CONF_FILES+=		${EGDIR}/completions.zsh \
			${PREFIX}/share/zsh/site-functions/_exa

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/cargo build --locked --frozen --release

do-install:
	${MKDIR} ${DESTDIR}${EGDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/exa ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/contrib/man/exa.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/contrib/completions.bash ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/completions.fish ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/completions.zsh ${DESTDIR}${EGDIR}


.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
