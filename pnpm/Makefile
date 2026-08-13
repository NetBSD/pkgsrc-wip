# $NetBSD$

PKGNAME=	pnpm-12.0.0rc2
DISTNAME=	pnpm-11.21.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=pnpm/}
GITHUB_TAG=	refs/tags/v${DISTNAME:C/^.*-//}

MAINTAINER=	iquiw@NetBSD.org
HOMEPAGE=	https://pnpm.io/
COMMENT=	Fast, disk space efficient package manager
LICENSE=	mit

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	bin

REPLACE_SH+=		pn pnx pnpx

CARGO_ARGS=		build --release --bin pnpm ${DEFAULT_CARGO_ARGS}
CARGO_INSTALL_ARGS=	install --path pnpm/crates/cli --root ${DESTDIR}${PREFIX} ${DEFAULT_CARGO_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/pnpm ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/pnpm/npm/pnpm/pn ${DESTDIR}${PREFIX}/bin/pn
	${INSTALL_SCRIPT} ${WRKSRC}/pnpm/npm/pnpm/pnx ${DESTDIR}${PREFIX}/bin/pnx
	${INSTALL_SCRIPT} ${WRKSRC}/pnpm/npm/pnpm/pnpx ${DESTDIR}${PREFIX}/bin/pnpx

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
