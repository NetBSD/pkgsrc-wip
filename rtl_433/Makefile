# $NetBSD$

GITHUB_PROJECT=	rtl_433
GITHUB_TAG=	23.11
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=merbanan/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://triq.org/rtl_433/
COMMENT=	Generic data receiver and decoder using software defined radio
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME}

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config pax
AUTO_MKDIRS=	yes

# \todo Remove or add a comment justifying.
#CMAKE_CONFIGURE_ARGS+=	-Wno-dev

# \todo Remove or add a comment justifying.
#CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_MANDIR=${PREFIX}/${PKGMANDIR}
#CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_WITH_INSTALL_RPATH=TRUE
#CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}
#CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_RPATH=${PREFIX}/lib
#CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH=FALSE

# \todo Remove or add a comment justifying.
#CMAKE_ARG_PATH=		../
#CONFIGURE_DIRS=		build

PKG_SYSCONFSUBDIR=	rtl_433
# missing CONF_FILES?

PKGCONFIG_OVERRIDE+=	rtl433.pc.in

# \todo Remove or add a comment justifying.
#pre-configure:
#	${RUN} ${MKDIR} ${WRKSRC}/build

# \todo Fix to install into examples/conf instead of removing, probably.
pre-build:
	${RM} ${WRKSRC}/conf/CMakeLists.txt

post-install:
	# \todo File a bug upstream about needing to install the manpage.
	${INSTALL_MAN} ${WRKSRC}/man/man1/rtl_433.1 \
	        ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${RM} -rf ${DESTDIR}${PREFIX}/share/man
	cd ${WRKSRC}/examples && ${PAX} -wr . ${DESTDIR}${PREFIX}/share/examples/rtl_433/
	cd ${WRKSRC}/conf && ${PAX} -wr . ${DESTDIR}${PREFIX}/share/examples/rtl_433/conf/
	cd ${WRKSRC}/docs && ${PAX} -wr . ${DESTDIR}${PREFIX}/share/doc/rtl_433/
	# \todo remove in source before copying, to be cleaner
	${RM} ${DESTDIR}${PREFIX}/share/doc/rtl_433/.gitignore

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
