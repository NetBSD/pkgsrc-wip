# $NetBSD$

DISTNAME=	CodeWhale-0.8.62
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Hmbown/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Hmbown/CodeWhale/
COMMENT=	DeepSeek V4 harness
LICENSE=	mit

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

# Install both binary crates via separate cargo install invocations
# (cargo install does not accept multiple --path flags).
# crates/app-server has autobins=false -- library-only, no binary.
CARGO_INSTALL_ARGS=	install \
			--path crates/tui \
			--root ${DESTDIR}${PREFIX} ${DEFAULT_CARGO_ARGS}

post-install:
	cd ${CARGO_WRKSRC} && ${SETENV} ${MAKE_ENV} ${CARGO} install \
		--path crates/cli \
		--root ${DESTDIR}${PREFIX} ${DEFAULT_CARGO_ARGS}
	${RM} -f ${DESTDIR}${PREFIX}/.crates.toml
	${RM} -f ${DESTDIR}${PREFIX}/.crates2.json

.include "cargo-depends.mk"

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../lang/rust/cargo.mk"

# Fix crate download URLs: cargo.mk constructs paths in the CDN format
# {name}/{name}-{version}.crate but sets MASTER_SITE_CRATESIO to the
# API host https://crates.io/api/v1/crates/ which returns 400 Bad Request.
# Override each SITES.*.crate entry to use the CDN directly.
.for crate in ${CARGO_CRATE_DEPENDS}
SITES.${crate}.crate=	-https://static.crates.io/crates/${crate:C/-[0-9]+\.[0-9.]+.*$//}/${crate}.crate
.endfor

.include "../../mk/bsd.pkg.mk"
