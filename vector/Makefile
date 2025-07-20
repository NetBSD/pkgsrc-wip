# $NetBSD$

DISTNAME=	vector-0.48.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=vectordotdev/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://vector.dev/
COMMENT=	High-performance observability data pipeline
LICENSE=	mpl-2.0

#.include "cargo-depends.mk"

#INSTALLATION_DIRS+=	bin
#
#do-install:
#	${INSTALL_PROGRAM} ${WRKSRC}/target/release/sg \
#		${DESTDIR}${PREFIX}/bin
#	${INSTALL_PROGRAM} ${WRKSRC}/target/release/ast-grep \
#		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
