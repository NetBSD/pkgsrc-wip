# $NetBSD$

DISTNAME=	v0.7.2
PKGNAME=	garage-${DISTNAME:S,^v,,}
CATEGORIES=	www
MASTER_SITES=	https://git.deuxfleurs.fr/Deuxfleurs/garage/archive/

MAINTAINER=	jhonas.wernery@mnxsolutions.com
HOMEPAGE=	https://git.deuxfleurs.fr/Deuxfleurs
COMMENT=	S3-compatible object store for small self-hosted deployments
LICENSE=	gnu-agpl-v3

WRKSRC=		${WRKDIR}/garage

.include "cargo-depends.mk"

MAKE_ENV+=	SODIUM_LIB_DIR=${BUILDLINK_PREFIX.libsodium}/lib
MAKE_ENV+=	PROTOC=${PREFIX}/bin/protoc

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/garage ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../lang/rust/rust.mk"
.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
