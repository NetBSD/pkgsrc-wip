# $NetBSD$

DISTNAME=	spotifyd-0.2.8
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=Spotifyd/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	base@atomicules.co.uk
HOMEPAGE=	https://github.com/Spotifyd/spotifyd/
COMMENT=	Open source Spotify client running as a UNIX daemon

LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c # rust, but needs a toolchain to link

DISTFILES=	${DEFAULT_DISTFILES}

LIBRESPOT_REV=	a41ab28540537e5f277fc9556bbcc16e08f065d5
DISTFILES+=	librespot-${LIBRESPOT_REV}.tar.gz
SITES.librespot-${LIBRESPOT_REV}.tar.gz=	-https://github.com/librespot-org/librespot/archive/${LIBRESPOT_REV}.tar.gz

RUST_TREMOR_REV=5958cc302e78f535dad90e9665da981ddff4000a
DISTFILES+=	rust-tremor-${RUST_TREMOR_REV}.tar.gz
SITES.rust-tremor-${RUST_TREMOR_REV}.tar.gz=	-https://github.com/plietar/rust-tremor/archive/${RUST_TREMOR_REV}.tar.gz

RUST_MDNS_REV=	66a74033da6c9f1a06e7b0a29f4544fd189d6479
DISTFILES+=	rust-mdns-${RUST_MDNS_REV}.tar.gz
SITES.rust-mdns-${RUST_MDNS_REV}.tar.gz=	-https://github.com/plietar/rust-mdns/archive/${RUST_MDNS_REV}.tar.gz

RUST_ALSA_REV=	8c63543fa0ccd971cf15f5675293d19febd6f79e
DISTFILES+=	rust-alsa-${RUST_ALSA_REV}.tar.gz
SITES.rust-alsa-${RUST_ALSA_REV}.tar.gz=	-https://github.com/plietar/rust-alsa/archive/${RUST_ALSA_REV}.tar.gz

DNS_PARSER_REV=	1d3e5a5591bc72eb061c23bd426c4a25f2f73791
DISTFILES+=	dns-parser-${DNS_PARSER_REV}.tar.gz
SITES.dns-parser-${DNS_PARSER_REV}.tar.gz=	-https://github.com/plietar/dns-parser/archive/${DNS_PARSER_REV}.tar.gz

# generate using make show-crate-depends
CARGO_CRATE_DEPENDS+=	MacTypes-sys-2.1.0
CARGO_CRATE_DEPENDS+=	adler32-1.0.3
CARGO_CRATE_DEPENDS+=	advapi32-sys-0.2.0
CARGO_CRATE_DEPENDS+=	aes-0.3.2
CARGO_CRATE_DEPENDS+=	aes-ctr-0.3.0
CARGO_CRATE_DEPENDS+=	aes-soft-0.3.3
CARGO_CRATE_DEPENDS+=	aesni-0.6.0
CARGO_CRATE_DEPENDS+=	aho-corasick-0.6.10
CARGO_CRATE_DEPENDS+=	alsa-0.2.1
CARGO_CRATE_DEPENDS+=	alsa-sys-0.1.2
CARGO_CRATE_DEPENDS+=	ansi_term-0.11.0
CARGO_CRATE_DEPENDS+=	arc-swap-0.3.7
CARGO_CRATE_DEPENDS+=	arrayvec-0.4.10
CARGO_CRATE_DEPENDS+=	atty-0.2.11
CARGO_CRATE_DEPENDS+=	autocfg-0.1.2
CARGO_CRATE_DEPENDS+=	backtrace-0.3.14
CARGO_CRATE_DEPENDS+=	backtrace-sys-0.1.28
CARGO_CRATE_DEPENDS+=	base64-0.10.1
CARGO_CRATE_DEPENDS+=	base64-0.5.2
CARGO_CRATE_DEPENDS+=	base64-0.6.0
CARGO_CRATE_DEPENDS+=	base64-0.9.3
CARGO_CRATE_DEPENDS+=	bit-set-0.4.0
CARGO_CRATE_DEPENDS+=	bit-vec-0.4.4
CARGO_CRATE_DEPENDS+=	bitflags-0.3.3
CARGO_CRATE_DEPENDS+=	bitflags-0.7.0
CARGO_CRATE_DEPENDS+=	bitflags-0.9.1
CARGO_CRATE_DEPENDS+=	bitflags-1.0.4
CARGO_CRATE_DEPENDS+=	block-buffer-0.7.0
CARGO_CRATE_DEPENDS+=	block-cipher-trait-0.6.2
CARGO_CRATE_DEPENDS+=	block-modes-0.2.0
CARGO_CRATE_DEPENDS+=	block-padding-0.1.3
CARGO_CRATE_DEPENDS+=	build_const-0.2.1
CARGO_CRATE_DEPENDS+=	byte-tools-0.3.1
CARGO_CRATE_DEPENDS+=	byteorder-0.5.3
CARGO_CRATE_DEPENDS+=	byteorder-1.3.1
CARGO_CRATE_DEPENDS+=	bytes-0.4.12
CARGO_CRATE_DEPENDS+=	c_linked_list-1.1.1
CARGO_CRATE_DEPENDS+=	cc-1.0.31
CARGO_CRATE_DEPENDS+=	cfg-if-0.1.7
CARGO_CRATE_DEPENDS+=	chrono-0.4.6
CARGO_CRATE_DEPENDS+=	clap-2.32.0
CARGO_CRATE_DEPENDS+=	cloudabi-0.0.3
CARGO_CRATE_DEPENDS+=	core-foundation-0.5.1
CARGO_CRATE_DEPENDS+=	core-foundation-sys-0.5.1
CARGO_CRATE_DEPENDS+=	crc-1.8.1
CARGO_CRATE_DEPENDS+=	crc32fast-1.2.0
CARGO_CRATE_DEPENDS+=	crossbeam-deque-0.7.1
CARGO_CRATE_DEPENDS+=	crossbeam-epoch-0.7.1
CARGO_CRATE_DEPENDS+=	crossbeam-queue-0.1.2
CARGO_CRATE_DEPENDS+=	crossbeam-utils-0.6.5
CARGO_CRATE_DEPENDS+=	crypto-mac-0.7.0
CARGO_CRATE_DEPENDS+=	ctr-0.3.2
CARGO_CRATE_DEPENDS+=	daemonize-0.3.0
CARGO_CRATE_DEPENDS+=	dbus-0.2.3
CARGO_CRATE_DEPENDS+=	dbus-0.6.4
CARGO_CRATE_DEPENDS+=	dbus-tokio-0.2.1
CARGO_CRATE_DEPENDS+=	derive-error-chain-0.10.1
CARGO_CRATE_DEPENDS+=	derive_builder-0.5.1
CARGO_CRATE_DEPENDS+=	derive_builder_core-0.2.0
CARGO_CRATE_DEPENDS+=	digest-0.8.0
CARGO_CRATE_DEPENDS+=	dotenv-0.10.1
CARGO_CRATE_DEPENDS+=	dtoa-0.4.3
CARGO_CRATE_DEPENDS+=	either-1.5.1
CARGO_CRATE_DEPENDS+=	encoding_rs-0.8.17
CARGO_CRATE_DEPENDS+=	env_logger-0.4.3
CARGO_CRATE_DEPENDS+=	env_logger-0.5.13
CARGO_CRATE_DEPENDS+=	error-chain-0.10.0
CARGO_CRATE_DEPENDS+=	error-chain-0.11.0
CARGO_CRATE_DEPENDS+=	extprim-1.6.0
CARGO_CRATE_DEPENDS+=	failure-0.1.5
CARGO_CRATE_DEPENDS+=	failure_derive-0.1.5
CARGO_CRATE_DEPENDS+=	fake-simd-0.1.2
CARGO_CRATE_DEPENDS+=	flate2-1.0.7
CARGO_CRATE_DEPENDS+=	fnv-1.0.6
CARGO_CRATE_DEPENDS+=	foreign-types-0.3.2
CARGO_CRATE_DEPENDS+=	foreign-types-shared-0.1.1
CARGO_CRATE_DEPENDS+=	fuchsia-cprng-0.1.1
CARGO_CRATE_DEPENDS+=	fuchsia-zircon-0.3.3
CARGO_CRATE_DEPENDS+=	fuchsia-zircon-sys-0.3.3
CARGO_CRATE_DEPENDS+=	futures-0.1.25
CARGO_CRATE_DEPENDS+=	futures-cpupool-0.1.8
CARGO_CRATE_DEPENDS+=	gcc-0.3.55
CARGO_CRATE_DEPENDS+=	generic-array-0.12.0
CARGO_CRATE_DEPENDS+=	get_if_addrs-0.5.3
CARGO_CRATE_DEPENDS+=	get_if_addrs-sys-0.1.1
CARGO_CRATE_DEPENDS+=	getopts-0.2.18
CARGO_CRATE_DEPENDS+=	h2-0.1.17
CARGO_CRATE_DEPENDS+=	hex-0.3.2
CARGO_CRATE_DEPENDS+=	hmac-0.7.0
CARGO_CRATE_DEPENDS+=	hostname-0.1.5
CARGO_CRATE_DEPENDS+=	http-0.1.16
CARGO_CRATE_DEPENDS+=	httparse-1.3.3
CARGO_CRATE_DEPENDS+=	humantime-1.2.0
CARGO_CRATE_DEPENDS+=	hyper-0.11.27
CARGO_CRATE_DEPENDS+=	hyper-0.12.25
CARGO_CRATE_DEPENDS+=	hyper-proxy-0.4.1
CARGO_CRATE_DEPENDS+=	hyper-tls-0.3.2
CARGO_CRATE_DEPENDS+=	idna-0.1.5
CARGO_CRATE_DEPENDS+=	indexmap-1.0.2
CARGO_CRATE_DEPENDS+=	iovec-0.1.2
CARGO_CRATE_DEPENDS+=	itertools-0.7.11
CARGO_CRATE_DEPENDS+=	itoa-0.4.3
CARGO_CRATE_DEPENDS+=	kernel32-sys-0.2.2
CARGO_CRATE_DEPENDS+=	keyring-0.6.1
CARGO_CRATE_DEPENDS+=	language-tags-0.2.2
CARGO_CRATE_DEPENDS+=	lazy_static-0.2.11
CARGO_CRATE_DEPENDS+=	lazy_static-1.3.0
CARGO_CRATE_DEPENDS+=	lazycell-1.2.1
CARGO_CRATE_DEPENDS+=	lewton-0.9.4
CARGO_CRATE_DEPENDS+=	libc-0.2.50
CARGO_CRATE_DEPENDS+=	libdbus-sys-0.1.5
CARGO_CRATE_DEPENDS+=	libpulse-sys-0.0.0
CARGO_CRATE_DEPENDS+=	linear-map-1.2.0
CARGO_CRATE_DEPENDS+=	lock_api-0.1.5
CARGO_CRATE_DEPENDS+=	log-0.3.9
CARGO_CRATE_DEPENDS+=	log-0.4.6
CARGO_CRATE_DEPENDS+=	matches-0.1.8
CARGO_CRATE_DEPENDS+=	memchr-2.2.0
CARGO_CRATE_DEPENDS+=	memoffset-0.2.1
CARGO_CRATE_DEPENDS+=	mime-0.3.13
CARGO_CRATE_DEPENDS+=	mime_guess-2.0.0-alpha.6
# work around weird version pattern not supported by cargo.mk
SITES.mime_guess-2.0.0-alpha.6.crate+=	-https://crates.io/api/v1/crates/mime_guess/2.0.0-alpha.6/download
CARGO_CRATE_DEPENDS+=	miniz_oxide-0.2.1
CARGO_CRATE_DEPENDS+=	miniz_oxide_c_api-0.2.1
CARGO_CRATE_DEPENDS+=	mio-0.6.16
CARGO_CRATE_DEPENDS+=	mio-named-pipes-0.1.6
CARGO_CRATE_DEPENDS+=	mio-uds-0.6.7
CARGO_CRATE_DEPENDS+=	miow-0.2.1
CARGO_CRATE_DEPENDS+=	miow-0.3.3
CARGO_CRATE_DEPENDS+=	multimap-0.4.0
CARGO_CRATE_DEPENDS+=	native-tls-0.2.2
CARGO_CRATE_DEPENDS+=	net2-0.2.33
CARGO_CRATE_DEPENDS+=	nix-0.11.0
CARGO_CRATE_DEPENDS+=	nix-0.9.0
CARGO_CRATE_DEPENDS+=	nodrop-0.1.13
CARGO_CRATE_DEPENDS+=	num-0.1.42
CARGO_CRATE_DEPENDS+=	num-bigint-0.1.44
CARGO_CRATE_DEPENDS+=	num-complex-0.1.43
CARGO_CRATE_DEPENDS+=	num-integer-0.1.39
CARGO_CRATE_DEPENDS+=	num-iter-0.1.37
CARGO_CRATE_DEPENDS+=	num-rational-0.1.42
CARGO_CRATE_DEPENDS+=	num-traits-0.1.43
CARGO_CRATE_DEPENDS+=	num-traits-0.2.6
CARGO_CRATE_DEPENDS+=	num_cpus-1.10.0
CARGO_CRATE_DEPENDS+=	ogg-0.7.0
CARGO_CRATE_DEPENDS+=	ogg-sys-0.0.9
CARGO_CRATE_DEPENDS+=	opaque-debug-0.2.2
CARGO_CRATE_DEPENDS+=	openssl-0.10.20
CARGO_CRATE_DEPENDS+=	openssl-probe-0.1.2
CARGO_CRATE_DEPENDS+=	openssl-sys-0.9.43
CARGO_CRATE_DEPENDS+=	owning_ref-0.4.0
CARGO_CRATE_DEPENDS+=	parking_lot-0.7.1
CARGO_CRATE_DEPENDS+=	parking_lot_core-0.4.0
CARGO_CRATE_DEPENDS+=	pbkdf2-0.3.0
CARGO_CRATE_DEPENDS+=	percent-encoding-1.0.1
CARGO_CRATE_DEPENDS+=	phf-0.7.24
CARGO_CRATE_DEPENDS+=	phf_codegen-0.7.24
CARGO_CRATE_DEPENDS+=	phf_generator-0.7.24
CARGO_CRATE_DEPENDS+=	phf_shared-0.7.24
CARGO_CRATE_DEPENDS+=	pkg-config-0.3.14
CARGO_CRATE_DEPENDS+=	portaudio-rs-0.3.0
CARGO_CRATE_DEPENDS+=	portaudio-sys-0.1.1
CARGO_CRATE_DEPENDS+=	proc-macro2-0.4.27
CARGO_CRATE_DEPENDS+=	protobuf-1.7.4
CARGO_CRATE_DEPENDS+=	protobuf-2.4.0
CARGO_CRATE_DEPENDS+=	protobuf-codegen-2.4.0
CARGO_CRATE_DEPENDS+=	protobuf-codegen-pure-2.4.0
CARGO_CRATE_DEPENDS+=	quick-error-1.2.2
CARGO_CRATE_DEPENDS+=	quote-0.3.15
CARGO_CRATE_DEPENDS+=	quote-0.6.11
CARGO_CRATE_DEPENDS+=	rand-0.3.23
CARGO_CRATE_DEPENDS+=	rand-0.4.6
CARGO_CRATE_DEPENDS+=	rand-0.5.6
CARGO_CRATE_DEPENDS+=	rand-0.6.5
CARGO_CRATE_DEPENDS+=	rand_chacha-0.1.1
CARGO_CRATE_DEPENDS+=	rand_core-0.3.1
CARGO_CRATE_DEPENDS+=	rand_core-0.4.0
CARGO_CRATE_DEPENDS+=	rand_hc-0.1.0
CARGO_CRATE_DEPENDS+=	rand_isaac-0.1.1
CARGO_CRATE_DEPENDS+=	rand_jitter-0.1.3
CARGO_CRATE_DEPENDS+=	rand_os-0.1.3
CARGO_CRATE_DEPENDS+=	rand_pcg-0.1.2
CARGO_CRATE_DEPENDS+=	rand_xorshift-0.1.1
CARGO_CRATE_DEPENDS+=	random-0.12.2
CARGO_CRATE_DEPENDS+=	rdrand-0.4.0
CARGO_CRATE_DEPENDS+=	redox_syscall-0.1.51
CARGO_CRATE_DEPENDS+=	redox_termios-0.1.1
CARGO_CRATE_DEPENDS+=	regex-0.2.11
CARGO_CRATE_DEPENDS+=	regex-1.1.2
CARGO_CRATE_DEPENDS+=	regex-syntax-0.5.6
CARGO_CRATE_DEPENDS+=	regex-syntax-0.6.5
CARGO_CRATE_DEPENDS+=	relay-0.1.1
CARGO_CRATE_DEPENDS+=	remove_dir_all-0.5.1
CARGO_CRATE_DEPENDS+=	reqwest-0.9.12
CARGO_CRATE_DEPENDS+=	rpassword-0.3.1
CARGO_CRATE_DEPENDS+=	rpassword-2.1.0
CARGO_CRATE_DEPENDS+=	rspotify-0.2.5
CARGO_CRATE_DEPENDS+=	rust-crypto-0.2.36
CARGO_CRATE_DEPENDS+=	rust-gmp-0.3.2
CARGO_CRATE_DEPENDS+=	rust-ini-0.13.0
CARGO_CRATE_DEPENDS+=	rustc-demangle-0.1.13
CARGO_CRATE_DEPENDS+=	rustc-serialize-0.3.24
CARGO_CRATE_DEPENDS+=	rustc_version-0.2.3
CARGO_CRATE_DEPENDS+=	ryu-0.2.7
CARGO_CRATE_DEPENDS+=	safemem-0.2.0
CARGO_CRATE_DEPENDS+=	safemem-0.3.0
CARGO_CRATE_DEPENDS+=	schannel-0.1.15
CARGO_CRATE_DEPENDS+=	scoped-tls-0.1.2
CARGO_CRATE_DEPENDS+=	scopeguard-0.3.3
CARGO_CRATE_DEPENDS+=	secret-service-0.4.0
CARGO_CRATE_DEPENDS+=	security-framework-0.2.2
CARGO_CRATE_DEPENDS+=	security-framework-sys-0.2.3
CARGO_CRATE_DEPENDS+=	semver-0.9.0
CARGO_CRATE_DEPENDS+=	semver-parser-0.7.0
CARGO_CRATE_DEPENDS+=	serde-1.0.89
CARGO_CRATE_DEPENDS+=	serde_derive-1.0.89
CARGO_CRATE_DEPENDS+=	serde_json-1.0.39
CARGO_CRATE_DEPENDS+=	serde_urlencoded-0.5.4
CARGO_CRATE_DEPENDS+=	sha-1-0.8.1
CARGO_CRATE_DEPENDS+=	sha2-0.8.0
CARGO_CRATE_DEPENDS+=	shannon-0.2.0
CARGO_CRATE_DEPENDS+=	signal-hook-0.1.8
CARGO_CRATE_DEPENDS+=	simplelog-0.4.4
CARGO_CRATE_DEPENDS+=	siphasher-0.2.3
CARGO_CRATE_DEPENDS+=	slab-0.3.0
CARGO_CRATE_DEPENDS+=	slab-0.4.2
CARGO_CRATE_DEPENDS+=	smallvec-0.2.1
CARGO_CRATE_DEPENDS+=	smallvec-0.6.9
CARGO_CRATE_DEPENDS+=	socket2-0.2.4
CARGO_CRATE_DEPENDS+=	socket2-0.3.8
CARGO_CRATE_DEPENDS+=	stable_deref_trait-1.1.1
CARGO_CRATE_DEPENDS+=	stream-cipher-0.3.0
CARGO_CRATE_DEPENDS+=	string-0.1.3
CARGO_CRATE_DEPENDS+=	strsim-0.7.0
CARGO_CRATE_DEPENDS+=	subtle-1.0.0
CARGO_CRATE_DEPENDS+=	syn-0.11.11
CARGO_CRATE_DEPENDS+=	syn-0.15.29
CARGO_CRATE_DEPENDS+=	synom-0.11.3
CARGO_CRATE_DEPENDS+=	synstructure-0.10.1
CARGO_CRATE_DEPENDS+=	syslog-4.0.1
CARGO_CRATE_DEPENDS+=	take-0.1.0
CARGO_CRATE_DEPENDS+=	tempfile-2.2.0
CARGO_CRATE_DEPENDS+=	tempfile-3.0.7
CARGO_CRATE_DEPENDS+=	term-0.4.6
CARGO_CRATE_DEPENDS+=	termcolor-1.0.4
CARGO_CRATE_DEPENDS+=	termion-1.5.1
CARGO_CRATE_DEPENDS+=	termios-0.2.2
CARGO_CRATE_DEPENDS+=	textwrap-0.10.0
CARGO_CRATE_DEPENDS+=	thread_local-0.3.6
CARGO_CRATE_DEPENDS+=	time-0.1.42
CARGO_CRATE_DEPENDS+=	tokio-0.1.18
CARGO_CRATE_DEPENDS+=	tokio-codec-0.1.1
CARGO_CRATE_DEPENDS+=	tokio-core-0.1.17
CARGO_CRATE_DEPENDS+=	tokio-current-thread-0.1.6
CARGO_CRATE_DEPENDS+=	tokio-executor-0.1.7
CARGO_CRATE_DEPENDS+=	tokio-fs-0.1.6
CARGO_CRATE_DEPENDS+=	tokio-io-0.1.12
CARGO_CRATE_DEPENDS+=	tokio-process-0.2.3
CARGO_CRATE_DEPENDS+=	tokio-proto-0.1.1
CARGO_CRATE_DEPENDS+=	tokio-reactor-0.1.9
CARGO_CRATE_DEPENDS+=	tokio-service-0.1.0
CARGO_CRATE_DEPENDS+=	tokio-signal-0.1.5
CARGO_CRATE_DEPENDS+=	tokio-signal-0.2.8
CARGO_CRATE_DEPENDS+=	tokio-sync-0.1.4
CARGO_CRATE_DEPENDS+=	tokio-tcp-0.1.3
CARGO_CRATE_DEPENDS+=	tokio-threadpool-0.1.13
CARGO_CRATE_DEPENDS+=	tokio-timer-0.2.10
CARGO_CRATE_DEPENDS+=	tokio-trace-core-0.1.0
CARGO_CRATE_DEPENDS+=	tokio-udp-0.1.3
CARGO_CRATE_DEPENDS+=	tokio-uds-0.2.5
CARGO_CRATE_DEPENDS+=	try-lock-0.1.0
CARGO_CRATE_DEPENDS+=	try-lock-0.2.2
CARGO_CRATE_DEPENDS+=	typenum-1.10.0
CARGO_CRATE_DEPENDS+=	ucd-util-0.1.3
CARGO_CRATE_DEPENDS+=	unicase-1.4.2
CARGO_CRATE_DEPENDS+=	unicase-2.3.0
CARGO_CRATE_DEPENDS+=	unicode-bidi-0.3.4
CARGO_CRATE_DEPENDS+=	unicode-normalization-0.1.8
CARGO_CRATE_DEPENDS+=	unicode-width-0.1.5
CARGO_CRATE_DEPENDS+=	unicode-xid-0.0.4
CARGO_CRATE_DEPENDS+=	unicode-xid-0.1.0
CARGO_CRATE_DEPENDS+=	url-1.7.2
CARGO_CRATE_DEPENDS+=	utf8-ranges-1.0.2
CARGO_CRATE_DEPENDS+=	uuid-0.4.0
CARGO_CRATE_DEPENDS+=	uuid-0.7.2
CARGO_CRATE_DEPENDS+=	vcpkg-0.2.6
CARGO_CRATE_DEPENDS+=	vec_map-0.8.1
CARGO_CRATE_DEPENDS+=	vergen-0.1.1
CARGO_CRATE_DEPENDS+=	version_check-0.1.5
CARGO_CRATE_DEPENDS+=	void-1.0.2
CARGO_CRATE_DEPENDS+=	want-0.0.4
CARGO_CRATE_DEPENDS+=	want-0.0.6
CARGO_CRATE_DEPENDS+=	webbrowser-0.2.2
CARGO_CRATE_DEPENDS+=	winapi-0.2.8
CARGO_CRATE_DEPENDS+=	winapi-0.3.6
CARGO_CRATE_DEPENDS+=	winapi-build-0.1.1
CARGO_CRATE_DEPENDS+=	winapi-i686-pc-windows-gnu-0.4.0
CARGO_CRATE_DEPENDS+=	winapi-util-0.1.2
CARGO_CRATE_DEPENDS+=	winapi-x86_64-pc-windows-gnu-0.4.0
CARGO_CRATE_DEPENDS+=	wincolor-1.0.1
CARGO_CRATE_DEPENDS+=	winutil-0.1.1
CARGO_CRATE_DEPENDS+=	ws2_32-sys-0.2.1
CARGO_CRATE_DEPENDS+=	xdg-2.2.0

MAKE_ENV+=		OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
INSTALLATION_DIRS+=	bin

MAKE_ENV+= RUSTFLAGS="-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.pulseaudio}/lib -C link-arg=-L${BUILDLINK_PREFIX.pulseaudio}/lib"

# TODO investigate why this is needed
CHECK_WRKREF_SKIP+=	bin/spotifyd

post-extract:
	mv ${WRKDIR}/librespot-${LIBRESPOT_REV} ${WRKDIR}/librespot
	mv ${WRKDIR}/rust-tremor-${RUST_TREMOR_REV} ${WRKDIR}/rust-tremor
	mv ${WRKDIR}/rust-mdns-${RUST_MDNS_REV} ${WRKDIR}/rust-mdns
	mv ${WRKDIR}/rust-alsa-${RUST_ALSA_REV} ${WRKDIR}/rust-alsa
	mv ${WRKDIR}/dns-parser-${DNS_PARSER_REV} ${WRKDIR}/dns-parser

# NOTE: To update this package I think you need to do:
# 1. remove `--frozen --locked` below
# 2. `make extract`
# 3. `make patch`
# 4. `cd` into working directory
# 5. `cargo update` to update the lock file
# 6. `pkgdiff Cargo.lock Cargo.lock.orig > patch-Cargo.lock
# 7. Replace the file in `patches/` with that one
# 8. Can then re-add `--frozen --locked` below
#
do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/cargo build --no-default-features --features pulseaudio_backend --release --frozen --locked

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/spotifyd ${DESTDIR}${PREFIX}/bin

# Spotifyd now uses 2018 edition, need more recent version of rust.
# NOTE: It's up to you how you meet this version requirement. The last pkgsrc
# binary I can find for rust is 1.29.1 in 8.0_2018Q3. You can either build a
# required version or cheat by installing rust via rustup and "tricking" pkgsrc
# into using that.
BUILDLINK_API_DEPENDS.rust+=   rust>=1.31.0
.include "../../lang/rust/cargo.mk"
.include "../../lang/rust/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
