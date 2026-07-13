# $NetBSD$

DISTNAME=	libwebm-1.0.0.32
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=webmproject/}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.webmproject.org/
COMMENT=	High-quality, open and free video format for the web
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/libwebm-${DISTNAME}
USE_LANGUAGES=	c++

CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON

# upstream doesn't provide a pkg-config file, so make one
# https://issues.webmproject.org/issues/534208996
SUBST_CLASSES+=		pc
SUBST_FILES.pc+=	libwebm.pc
SUBST_VARS.pc+=		PREFIX
SUBST_SED.pc+=		-e "s,@PACKAGE_VERSION@,${PKGVERSION_NOREV},"
SUBST_STAGE.pc=		pre-configure
SUBST_MESSAGE.pc=	Filling in details into pkg-config file.

PKGCONFIG_OVERRIDE+=	libwebm.pc

INSTALLATION_DIRS+=	lib/pkgconfig

post-extract:
	cp ${FILESDIR}/libwebm.pc ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/libwebm.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
