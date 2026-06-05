# $NetBSD$

DISTNAME=	CodeWhale-0.8.53
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Hmbown/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Hmbown/CodeWhale/
COMMENT=	Terminal-based AI coding agent (formerly DeepSeek-TUI)
LICENSE=	mit

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c

CARGO_INSTALL_ARGS=	install --path crates/tui --root ${DESTDIR}${PREFIX} ${DEFAULT_CARGO_ARGS}

.include "../../mk/bsd.prefs.mk"

# dbus-1 is a Linux-only dep (system tray); use pkgsrc dbus via buildlink
.if ${OPSYS} == "Linux"
USE_TOOLS+=		pkg-config
TOOLS_PATH.pkg-config=	/usr/pkg/bin/pkg-config
.include "../../sysutils/dbus/buildlink3.mk"
.endif

post-install:
	cd ${CARGO_WRKSRC} && ${SETENV} ${MAKE_ENV} ${CARGO} install --path crates/app-server --root ${DESTDIR}${PREFIX} ${DEFAULT_CARGO_ARGS}
	cd ${CARGO_WRKSRC} && ${SETENV} ${MAKE_ENV} ${CARGO} install --path crates/cli --root ${DESTDIR}${PREFIX} ${DEFAULT_CARGO_ARGS}
	rm -f ${DESTDIR}${PREFIX}/.crates.toml ${DESTDIR}${PREFIX}/.crates2.json

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
