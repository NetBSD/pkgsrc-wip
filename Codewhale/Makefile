# $NetBSD$

DISTNAME=	Codewhale-0.10.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Hmbown/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Hmbown/CodeWhale/
COMMENT=	Local-first coding-agent harness for DeepSeek V4
LICENSE=	mit

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config patch

# crates/cli owns the sole `codewhale` binary. As of 0.10.1 crates/tui is
# library-only (autobins=false, empty main.rs), so there is no codewhale-tui
# binary to install. The cargo.mk default `install --path .` cannot be used:
# the top-level Cargo.toml is a virtual manifest.
CARGO_INSTALL_ARGS=	install \
			--path crates/cli \
			--root ${DESTDIR}${PREFIX} ${DEFAULT_CARGO_ARGS}

# Use lld linker instead of GNU ld — much less memory during final link.
# Max codegen units + thin LTO spread LLVM work across smaller parallel invocations.
RUSTFLAGS+=		-C link-arg=-fuse-ld=lld
MAKE_ENV+=		CARGO_PROFILE_RELEASE_CODEGEN_UNITS=16
MAKE_ENV+=		CARGO_PROFILE_RELEASE_LTO=thin

# rquickjs-sys lacks pre-generated bindings for NetBSD targets.
# The Linux bindings are ABI-identical for QuickJS on the same CPU arch.
post-extract:
	${RUN} for f in ${WRKDIR}/vendor/rquickjs-sys-0.14.0/src/bindings/*-linux-gnu.rs; do \
		target=`${BASENAME} "$$f" | ${SED} 's/-linux-gnu/-netbsd/'`; \
		dest="${WRKDIR}/vendor/rquickjs-sys-0.14.0/src/bindings/$$target"; \
		if [ ! -f "$$dest" ]; then \
			${CP} "$$f" "$$dest"; \
		fi; \
		done

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/.crates.toml
	${RM} -f ${DESTDIR}${PREFIX}/.crates2.json

.include "cargo-depends.mk"

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
