# $NetBSD$

GITHUB_PROJECT=	rtl_433
GITHUB_TAG=	23.11
DISTNAME=	23.11
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
PKGREVISION=	
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=merbanan/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://triq.org/rtl_433/
COMMENT=	Generic data receiver
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME}/build

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
USE_CMAKE=	yes

CMAKE_ARG_PATH=	..
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_MANDIR=${PREFIX}/${PKGMANDIR}

PKGCONFIG_OVERRIDE+=	rtl433.pc.in

AUTO_MKDIRS=	yes

pre-configure:
	${RUN} ${MKDIR} ${WRKSRC}/build

post-install:
	${INSTALL_MAN} ${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME}/man/man1/rtl_433.1 \
	        ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${RM} -rf ${DESTDIR}${PREFIX}/share

.include "options.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
