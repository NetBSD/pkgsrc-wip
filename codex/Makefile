# $NetBSD$

DISTNAME=	codex-0.30.0
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
RATATUI_REV=		9b2ad1298408c45918ee9f8241a6f95498cdbed2
DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		ratatui-${RATATUI_REV}.tar.gz

SITES.ratatui-${RATATUI_REV}.tar.gz+=		-${MASTER_SITE_GITHUB:=nornagon/}ratatui/archive/${RATATUI_REV}.tar.gz

INSTALLATION_DIRS=	bin share/doc/codex

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/codex ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/../README.md ${DESTDIR}${PREFIX}/share/doc/codex

.include "cargo-depends.mk"
.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
