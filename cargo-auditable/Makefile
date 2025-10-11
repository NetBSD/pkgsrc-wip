# $NetBSD$

DISTNAME=	cargo-auditable-0.6.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rust-secure-code/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rust-secure-code/cargo-auditable/
COMMENT=	Make production Rust binaries auditable
LICENSE=	apache-2.0 OR mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cargo-auditable \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/auditable2cdx \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cargo-auditable/cargo-auditable.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/cargo-auditable.1

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
