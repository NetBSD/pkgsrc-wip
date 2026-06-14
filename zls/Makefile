# $NetBSD$

DISTNAME=	zls-0.16.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=zigtools/}
GITHUB_PROJECT=	zls
GITHUB_TAG=	${PKGVERSION_NOREV}

COMMENT=	Language Server for zig
MAINTAINER=	pkgsrc@NetBSD.org
HOMEPAGE=	https://github.com/zigtools/zls/
LICENSE=	mit

ZIGSTRIP=		no
ZIGBUILDARGS+=		--verbose

# Temporary required, a zig build system parser is being written.
ALLOW_NETWORK_ACCESS=	yes

# TODO: target "zig-vendor-packages" fails if build.zig does not exist in this directory.
# .include "zig-depends.mk"

.include "../../lang/zig/application.mk"
.include "../../mk/bsd.pkg.mk"
