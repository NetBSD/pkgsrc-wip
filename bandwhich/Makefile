# $NetBSD$

DISTNAME=	bandwhich-0.23.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=imsnif/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/imsnif/bandwhich/
COMMENT=	Terminal bandwidth utilization tool
LICENSE=	mit

USE_LANGUAGES=	c

# Depends on an unpublished crate. Can't use cargo.mk to fetch it.
PACKET_BUILD_REV=	bf5a89ba75795f5067bb03fa8de00b833ffe4eae
DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		packet-builder-${PACKET_BUILD_REV}.tar.gz

SITES.packet-builder-${PACKET_BUILD_REV}.tar.gz+=	-${MASTER_SITE_GITHUB:=cyqsimon/}packet_builder/archive/${PACKET_BUILD_REV}.tar.gz

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
