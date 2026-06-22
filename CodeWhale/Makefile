# $NetBSD$

DISTNAME=	CodeWhale-0.8.64
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Hmbown/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Hmbown/CodeWhale/
COMMENT=	Local-first coding-agent harness for DeepSeek V4
LICENSE=	mit

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

.include "../../mk/bsd.pkg.mk"
