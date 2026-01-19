# $NetBSD$

DISTNAME=	codex-0.87.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=openai/}
GITHUB_TAG=	rust-v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/openai/codex/
COMMENT=	Lightweight coding agent that runs in your terminal
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/codex-rust-v${PKGVERSION_NOREV}/codex-rs
USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config perl gmake

RUST_REQ=	1.89

# Depends on unpublished crates. Can't use cargo.mk to fetch them.
CROSSTERM_REV=		87db8bfa6dc99427fd3b071681b07fc31c6ce995
RATATUI_REV=		9b2ad1298408c45918ee9f8241a6f95498cdbed2
WEZTERM_REV=		fe38df8409545a696909aa9a09e63438630f217d
DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		crossterm-${CROSSTERM_REV}.tar.gz
DISTFILES+=		ratatui-${RATATUI_REV}.tar.gz
DISTFILES+=		wezterm-${WEZTERM_REV}.tar.gz

SITES.crossterm-${CROSSTERM_REV}.tar.gz+=	-${MASTER_SITE_GITHUB:=nornagon/}crossterm/archive/${CROSSTERM_REV}.tar.gz
SITES.ratatui-${RATATUI_REV}.tar.gz+=		-${MASTER_SITE_GITHUB:=nornagon/}ratatui/archive/${RATATUI_REV}.tar.gz
SITES.wezterm-${WEZTERM_REV}.tar.gz+=		-${MASTER_SITE_GITHUB:=pakrym/}wezterm/archive/${WEZTERM_REV}.tar.gz

INSTALLATION_DIRS=	bin share/doc/codex

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/codex ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/../README.md ${DESTDIR}${PREFIX}/share/doc/codex

.include "cargo-depends.mk"
.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
