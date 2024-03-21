# $NetBSD: Makefile,v 1.3 2023/07/08 20:14:16 pin Exp $

DISTNAME=	iamb-0.0.9
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=ulyssa/}
GITHUB_TAG=	8a5049fb25f698db25de32b681993f19f631cbed

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://iamb.chat/
COMMENT=	Matrix client for Vim addicts
LICENSE=	apache-2.0

.include "cargo-depends.mk"

# If you wish to build this package linking against native OpenSSL
# instead of rustls, uncomment all lines bellow.

#MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
#RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

#CARGO_NO_DEFAULT_FEATURES=	YES
#CARGO_FEATURES+=		native-tls

.include "../../lang/rust/cargo.mk"
#.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
