# $NetBSD$

DISTNAME=	asm-lsp-0.9.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=bergercookie/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bergercookie/asm-lsp
COMMENT=	Language server for NASM/GAS/GO Assembly
LICENSE=	2-clause-bsd

.include "cargo-depends.mk"

USE_LANGUAGES=	c c++

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

#INSTALLATION_DIRS+=	bin

#do-install:
#	${INSTALL_PROGRAM} ${WRKSRC}/target/release/sg \
#		${DESTDIR}${PREFIX}/bin
#	${INSTALL_PROGRAM} ${WRKSRC}/target/release/ast-grep \
#		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
