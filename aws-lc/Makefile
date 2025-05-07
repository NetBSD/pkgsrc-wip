# $NetBSD$

DISTNAME=	aws-lc-1.51.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=aws/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aws/aws-lc/
COMMENT=	General-purpose cryptographic library
LICENSE=	openssl AND mit AND isc

TOOL_DEPENDS+=	go-[0-9]*:../../lang/go

CONFLICTS+=	openssl-[0-9]*

USE_TOOLS+=	bash:run perl
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	pkgconfig/libcrypto.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/libssl.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/openssl.pc.in

REPLACE_BASH+=		tool-openssl/c_rehash.sh
# needed for testing
ALLOW_NETWORK_ACCESS=	yes
TEST_TARGET=		run_tests

pre-configure:
	${LN} -s ${PREFIX}/bin/go124 ${BUILDLINK_DIR}/bin/go

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
