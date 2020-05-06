# $NetBSD$

DISTNAME=	routinator-0.7.0
CATEGORIES=	net
EXTRACT_SUFX=	.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/NLnetLabs/routinator
COMMENT=	Validate RPKI ROA against routing announcements
LICENSE=	modified-bsd

# 0.7.0 now requires this rust version:
BUILDLINK_API_DEPENDS.rust+=	rust>=1.39.0

CARGO_CRATE_DEPENDS+=	ansi_term-0.11.0
CARGO_CRATE_DEPENDS+=	arc-swap-0.4.6
CARGO_CRATE_DEPENDS+=	arrayref-0.3.6
CARGO_CRATE_DEPENDS+=	arrayvec-0.5.1
CARGO_CRATE_DEPENDS+=	atty-0.2.14
CARGO_CRATE_DEPENDS+=	autocfg-1.0.0
CARGO_CRATE_DEPENDS+=	backtrace-0.3.46
CARGO_CRATE_DEPENDS+=	backtrace-sys-0.1.36
CARGO_CRATE_DEPENDS+=	base64-0.11.0
CARGO_CRATE_DEPENDS+=	base64-0.12.0
CARGO_CRATE_DEPENDS+=	bcder-0.5.0
CARGO_CRATE_DEPENDS+=	bitflags-1.2.1
CARGO_CRATE_DEPENDS+=	blake2b_simd-0.5.10
CARGO_CRATE_DEPENDS+=	boxfnonce-0.1.1
CARGO_CRATE_DEPENDS+=	bumpalo-3.2.1
CARGO_CRATE_DEPENDS+=	byteorder-1.3.4
CARGO_CRATE_DEPENDS+=	bytes-0.4.12
CARGO_CRATE_DEPENDS+=	bytes-0.5.4
CARGO_CRATE_DEPENDS+=	cc-1.0.52
CARGO_CRATE_DEPENDS+=	cfg-if-0.1.10
CARGO_CRATE_DEPENDS+=	chrono-0.4.11
CARGO_CRATE_DEPENDS+=	clap-2.33.0
CARGO_CRATE_DEPENDS+=	constant_time_eq-0.1.5
CARGO_CRATE_DEPENDS+=	core-foundation-0.7.0
CARGO_CRATE_DEPENDS+=	core-foundation-sys-0.7.0
CARGO_CRATE_DEPENDS+=	crossbeam-queue-0.2.1
CARGO_CRATE_DEPENDS+=	crossbeam-utils-0.7.2
CARGO_CRATE_DEPENDS+=	ct-logs-0.6.0
CARGO_CRATE_DEPENDS+=	daemonize-0.4.1
CARGO_CRATE_DEPENDS+=	dirs-2.0.2
CARGO_CRATE_DEPENDS+=	dirs-sys-0.3.4
CARGO_CRATE_DEPENDS+=	dtoa-0.4.5
CARGO_CRATE_DEPENDS+=	either-1.5.3
CARGO_CRATE_DEPENDS+=	encoding_rs-0.8.22
CARGO_CRATE_DEPENDS+=	error-chain-0.12.2
CARGO_CRATE_DEPENDS+=	fern-0.6.0
CARGO_CRATE_DEPENDS+=	fnv-1.0.6
CARGO_CRATE_DEPENDS+=	foreign-types-0.3.2
CARGO_CRATE_DEPENDS+=	foreign-types-shared-0.1.1
CARGO_CRATE_DEPENDS+=	fuchsia-zircon-0.3.3
CARGO_CRATE_DEPENDS+=	fuchsia-zircon-sys-0.3.3
CARGO_CRATE_DEPENDS+=	futures-0.3.4
CARGO_CRATE_DEPENDS+=	futures-channel-0.3.4
CARGO_CRATE_DEPENDS+=	futures-core-0.3.4
CARGO_CRATE_DEPENDS+=	futures-executor-0.3.4
CARGO_CRATE_DEPENDS+=	futures-io-0.3.4
CARGO_CRATE_DEPENDS+=	futures-macro-0.3.4
CARGO_CRATE_DEPENDS+=	futures-sink-0.3.4
CARGO_CRATE_DEPENDS+=	futures-task-0.3.4
CARGO_CRATE_DEPENDS+=	futures-util-0.3.4
CARGO_CRATE_DEPENDS+=	getrandom-0.1.14
CARGO_CRATE_DEPENDS+=	h2-0.2.4
CARGO_CRATE_DEPENDS+=	hermit-abi-0.1.12
CARGO_CRATE_DEPENDS+=	http-0.2.1
CARGO_CRATE_DEPENDS+=	http-body-0.3.1
CARGO_CRATE_DEPENDS+=	httparse-1.3.4
CARGO_CRATE_DEPENDS+=	hyper-0.13.5
CARGO_CRATE_DEPENDS+=	hyper-rustls-0.20.0
CARGO_CRATE_DEPENDS+=	hyper-tls-0.4.1
CARGO_CRATE_DEPENDS+=	idna-0.2.0
CARGO_CRATE_DEPENDS+=	indexmap-1.3.2
CARGO_CRATE_DEPENDS+=	iovec-0.1.4
CARGO_CRATE_DEPENDS+=	itoa-0.4.5
CARGO_CRATE_DEPENDS+=	js-sys-0.3.37
CARGO_CRATE_DEPENDS+=	json-0.12.4
CARGO_CRATE_DEPENDS+=	kernel32-sys-0.2.2
CARGO_CRATE_DEPENDS+=	lazy_static-1.4.0
CARGO_CRATE_DEPENDS+=	libc-0.2.69
CARGO_CRATE_DEPENDS+=	listenfd-0.3.3
CARGO_CRATE_DEPENDS+=	log-0.4.8
CARGO_CRATE_DEPENDS+=	log-reroute-0.1.5
CARGO_CRATE_DEPENDS+=	matches-0.1.8
CARGO_CRATE_DEPENDS+=	memchr-2.3.3
CARGO_CRATE_DEPENDS+=	mime-0.3.16
CARGO_CRATE_DEPENDS+=	mime_guess-2.0.3
CARGO_CRATE_DEPENDS+=	mio-0.6.21
CARGO_CRATE_DEPENDS+=	mio-uds-0.6.7
CARGO_CRATE_DEPENDS+=	miow-0.2.1
CARGO_CRATE_DEPENDS+=	native-tls-0.2.4
CARGO_CRATE_DEPENDS+=	net2-0.2.33
CARGO_CRATE_DEPENDS+=	num-integer-0.1.42
CARGO_CRATE_DEPENDS+=	num-traits-0.2.11
CARGO_CRATE_DEPENDS+=	num_cpus-1.13.0
CARGO_CRATE_DEPENDS+=	once_cell-1.3.1
CARGO_CRATE_DEPENDS+=	openssl-0.10.29
CARGO_CRATE_DEPENDS+=	openssl-probe-0.1.2
CARGO_CRATE_DEPENDS+=	openssl-sys-0.9.55
CARGO_CRATE_DEPENDS+=	percent-encoding-2.1.0
CARGO_CRATE_DEPENDS+=	pin-project-0.4.9
CARGO_CRATE_DEPENDS+=	pin-project-internal-0.4.9
CARGO_CRATE_DEPENDS+=	pin-project-lite-0.1.4
CARGO_CRATE_DEPENDS+=	pin-utils-0.1.0
CARGO_CRATE_DEPENDS+=	pkg-config-0.3.17
CARGO_CRATE_DEPENDS+=	ppv-lite86-0.2.6
CARGO_CRATE_DEPENDS+=	proc-macro-hack-0.5.15
CARGO_CRATE_DEPENDS+=	proc-macro-nested-0.1.4
CARGO_CRATE_DEPENDS+=	proc-macro2-1.0.10
CARGO_CRATE_DEPENDS+=	quick-xml-0.18.1
CARGO_CRATE_DEPENDS+=	quote-1.0.3
CARGO_CRATE_DEPENDS+=	rand-0.7.3
CARGO_CRATE_DEPENDS+=	rand_chacha-0.2.2
CARGO_CRATE_DEPENDS+=	rand_core-0.5.1
CARGO_CRATE_DEPENDS+=	rand_hc-0.2.0
CARGO_CRATE_DEPENDS+=	redox_syscall-0.1.56
CARGO_CRATE_DEPENDS+=	redox_users-0.3.4
CARGO_CRATE_DEPENDS+=	remove_dir_all-0.5.2
CARGO_CRATE_DEPENDS+=	reqwest-0.10.4
CARGO_CRATE_DEPENDS+=	ring-0.16.12
CARGO_CRATE_DEPENDS+=	rpki-0.9.1
CARGO_CRATE_DEPENDS+=	rpki-rtr-0.1.1
CARGO_CRATE_DEPENDS+=	rust-argon2-0.7.0
CARGO_CRATE_DEPENDS+=	rustc-demangle-0.1.16
CARGO_CRATE_DEPENDS+=	rustc_version-0.2.3
CARGO_CRATE_DEPENDS+=	rustls-0.17.0
CARGO_CRATE_DEPENDS+=	rustls-native-certs-0.3.0
CARGO_CRATE_DEPENDS+=	ryu-1.0.4
CARGO_CRATE_DEPENDS+=	schannel-0.1.18
CARGO_CRATE_DEPENDS+=	sct-0.6.0
CARGO_CRATE_DEPENDS+=	security-framework-0.4.3
CARGO_CRATE_DEPENDS+=	security-framework-sys-0.4.3
CARGO_CRATE_DEPENDS+=	semver-0.9.0
CARGO_CRATE_DEPENDS+=	semver-parser-0.7.0
CARGO_CRATE_DEPENDS+=	serde-1.0.106
CARGO_CRATE_DEPENDS+=	serde_derive-1.0.106
CARGO_CRATE_DEPENDS+=	serde_json-1.0.52
CARGO_CRATE_DEPENDS+=	serde_urlencoded-0.6.1
CARGO_CRATE_DEPENDS+=	signal-hook-registry-1.2.0
CARGO_CRATE_DEPENDS+=	slab-0.4.2
CARGO_CRATE_DEPENDS+=	smallvec-1.4.0
CARGO_CRATE_DEPENDS+=	spin-0.5.2
CARGO_CRATE_DEPENDS+=	strsim-0.8.0
CARGO_CRATE_DEPENDS+=	syn-1.0.18
CARGO_CRATE_DEPENDS+=	syslog-5.0.0
CARGO_CRATE_DEPENDS+=	tempfile-3.1.0
CARGO_CRATE_DEPENDS+=	textwrap-0.11.0
CARGO_CRATE_DEPENDS+=	thiserror-1.0.16
CARGO_CRATE_DEPENDS+=	thiserror-impl-1.0.16
CARGO_CRATE_DEPENDS+=	time-0.1.43
CARGO_CRATE_DEPENDS+=	tokio-0.2.13
CARGO_CRATE_DEPENDS+=	tokio-macros-0.2.5
CARGO_CRATE_DEPENDS+=	tokio-rustls-0.13.0
CARGO_CRATE_DEPENDS+=	tokio-socks-0.2.2
CARGO_CRATE_DEPENDS+=	tokio-tls-0.3.0
CARGO_CRATE_DEPENDS+=	tokio-util-0.3.1
CARGO_CRATE_DEPENDS+=	toml-0.5.6
CARGO_CRATE_DEPENDS+=	tower-service-0.3.0
CARGO_CRATE_DEPENDS+=	try-lock-0.2.2
CARGO_CRATE_DEPENDS+=	unicase-2.6.0
CARGO_CRATE_DEPENDS+=	unicode-bidi-0.3.4
CARGO_CRATE_DEPENDS+=	unicode-normalization-0.1.12
CARGO_CRATE_DEPENDS+=	unicode-width-0.1.7
CARGO_CRATE_DEPENDS+=	unicode-xid-0.2.0
CARGO_CRATE_DEPENDS+=	untrusted-0.7.1
CARGO_CRATE_DEPENDS+=	unwrap-1.2.1
CARGO_CRATE_DEPENDS+=	url-2.1.1
CARGO_CRATE_DEPENDS+=	uuid-0.6.5
CARGO_CRATE_DEPENDS+=	uuid-0.8.1
CARGO_CRATE_DEPENDS+=	vcpkg-0.2.8
CARGO_CRATE_DEPENDS+=	vec_map-0.8.1
CARGO_CRATE_DEPENDS+=	version_check-0.9.1
CARGO_CRATE_DEPENDS+=	want-0.3.0
CARGO_CRATE_DEPENDS+=	wasi-0.9.0+wasi-snapshot-preview1
CARGO_CRATE_DEPENDS+=	wasm-bindgen-0.2.60
CARGO_CRATE_DEPENDS+=	wasm-bindgen-backend-0.2.60
CARGO_CRATE_DEPENDS+=	wasm-bindgen-futures-0.4.10
CARGO_CRATE_DEPENDS+=	wasm-bindgen-macro-0.2.60
CARGO_CRATE_DEPENDS+=	wasm-bindgen-macro-support-0.2.60
CARGO_CRATE_DEPENDS+=	wasm-bindgen-shared-0.2.60
CARGO_CRATE_DEPENDS+=	web-sys-0.3.37
CARGO_CRATE_DEPENDS+=	webpki-0.21.2
CARGO_CRATE_DEPENDS+=	webpki-roots-0.18.0
CARGO_CRATE_DEPENDS+=	winapi-0.2.8
CARGO_CRATE_DEPENDS+=	winapi-0.3.8
CARGO_CRATE_DEPENDS+=	winapi-build-0.1.1
CARGO_CRATE_DEPENDS+=	winapi-i686-pc-windows-gnu-0.4.0
CARGO_CRATE_DEPENDS+=	winapi-x86_64-pc-windows-gnu-0.4.0
CARGO_CRATE_DEPENDS+=	winreg-0.6.2
CARGO_CRATE_DEPENDS+=	ws2_32-sys-0.2.1

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
EGDIR=		${PREFIX}/share/examples/${PKGBASE}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${DOCDIR} ${EGDIR}

.include "../../mk/bsd.prefs.mk"

# toolchain/54192, induces rtld issues
.if ${OPSYS} == "NetBSD"
MAKE_JOBS_SAFE=	no
.endif

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PREFIX}/bin/cargo \
		build --locked --frozen \
		-j ${_MAKE_JOBS_N}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/debug/routinator \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/routinator.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/./etc/routinator.conf.example \
		${DESTDIR}${EGDIR}

.include "../../lang/rust/cargo.mk"
.include "../../lang/rust/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
