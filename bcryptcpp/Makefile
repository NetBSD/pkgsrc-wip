# $NetBSD$

DISTNAME=	bcryptcpp-2.0.0.20231211
CATEGORIES=	devel security
#MASTER_SITES=	${MASTER_SITE_GITHUB:=hilch/}
MASTER_SITES=	${MASTER_SITE_GITHUB:=berthubert/}
GITHUB_TAG=	07f89a6cadb827512f9ab907174bec1a1c7c0f18
GITHUB_PROJECT=	Bcrypt.cpp

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/berthubert/Bcrypt.cpp/
COMMENT=	C++ wrapper around bcrypt password hashing
LICENSE=	original-bsd

USE_LANGUAGES=	c c++

SUBST_CLASSES+=		prefix
SUBST_VARS.prefix+=	PREFIX
SUBST_FILES.prefix=	bcryptcpp.pc
SUBST_STAGE.prefix=	post-configure
SUBST_MESSAGE.prefix=	Fix installation prefix in pkg-config file.

INSTALLATION_DIRS=	include lib lib/pkgconfig

post-extract:
	${CP} ${FILESDIR}/bcryptcpp.pc ${WRKSRC}

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/bcrypt.h ${DESTDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/${CMAKE_BUILD_DIR}/libbcrypt.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/bcryptcpp.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
