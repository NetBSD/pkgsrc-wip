# $NetBSD$

DISTNAME=	sem-0.13.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Ataraxy-Labs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Ataraxy-Labs/sem/
COMMENT=	Semantic version control
#ICENSE=	apache-2.0 AND mit # AND ?

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

WRKSRC=		${WRKDIR}/${DISTNAME}/crates

#CARGO_ARGS=	build --release ${DEFAULT_CARGO_ARGS} sem-cli
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${SSLBASE}/lib

CONFLICTS+=	parallel-[0-9]*

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/sem ${DESTDIR}${PREFIX}/bin

.include "cargo-crates.mk"

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
