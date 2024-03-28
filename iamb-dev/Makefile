# $NetBSD: Makefile,v 1.3 2023/07/08 20:14:16 pin Exp $

DISTNAME=	iamb-0.0.9
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=ulyssa/}
GITHUB_TAG=	79f6b5b75c1cff73c0f5cd77d0b1292359444876

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://iamb.chat/
COMMENT=	Matrix client for Vim addicts
LICENSE=	apache-2.0

.include "cargo-depends.mk"

INSTALLATION_DIRS=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5

# If you wish to build this package linking against native OpenSSL
# instead of rustls, uncomment all lines bellow.

#MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
#RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

#CARGO_NO_DEFAULT_FEATURES=	YES
#CARGO_FEATURES+=		native-tls

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/iamb.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/iamb.1
	${INSTALL_MAN} ${WRKSRC}/docs/iamb.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/iamb.5

.include "../../lang/rust/cargo.mk"
#.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
