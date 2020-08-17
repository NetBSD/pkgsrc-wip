# $NetBSD$
#
# Common logic that can be used by packages that build rust binaries.
#
# Usage example:
# See wip/rust-bindgen
#
#
# TODO:
# if openssl-* crate is included:
#    USE_LANGUAGES+= c c++
#    MAKE_ENV+= OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
#    .include "../../security/openssl/buildlink3.mk"
# endif
#
# if PKG_DEVELOPER=yes
#   make cargo action verbose?
#
# Fix this warning:
# WARN: Makefile:16: CARGO_CRATE_DEPENDS is defined but not used.


do-build: do-build-cargo-binary
.PHONY: do-build-cargo-binary

do-build-cargo-binary:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/cargo build --locked --frozen --release --jobs ${MAKE_JOBS:U1}

do-install: install-cargo-binary
.PHONY: install-cargo-binary

install-cargo-binary:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/cargo install --jobs ${MAKE_JOBS:U1} --path . --root ${DESTDIR}${LOCALBASE}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${RM} ${DESTDIR}${LOCALBASE}/.crates.toml

.include "../../lang/rust/cargo.mk"
