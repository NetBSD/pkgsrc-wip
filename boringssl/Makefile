# $NetBSD: Makefile,v 1.8 2017/04/13 15:12:06 bsiegert Exp $

DISTNAME=	boringssl-20220419
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://boringssl.googlesource.com/boringssl/
COMMENT=	Fork of OpenSSL designed to meet Google's needs
LICENSE=	openssl

WRKSRC=		${WRKDIR}/boringssl

USE_TOOLS+=		cmake perl
USE_LANGUAGES+=		c gnu++11
TEST_TARGET=		run_tests
CMAKE_INSTALL_PREFIX=	${PREFIX}/boringssl
CMAKE_CONFIGURE_ARGS+=		-DBUILD_SHARED_LIBS=ON

CFLAGS+=	-D_XOPEN_SOURCE=600 -D_NETBSD_SOURCE

BUILDLINK_TRANSFORM+=	rm:-Werror

SUBST_CLASSES+=		go
SUBST_STAGE.go=		pre-configure
SUBST_FILES.go=		CMakeLists.txt
SUBST_SED.go=		-e '/find_program.GO_EXECUTABLE/s,go,${GO},'

.include "go-modules.mk"
.include "../../devel/cmake/build.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
