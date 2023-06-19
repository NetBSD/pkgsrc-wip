# $NetBSD$

DISTNAME=	diesel-2.1.0
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=diesel-rs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://diesel.rs/
COMMENT=	CLI for the Diesel crate
LICENSE=	apache-2.0 AND mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.sqlite3}/lib

.include "../../lang/rust/cargo.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../databases/mariadb106-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
