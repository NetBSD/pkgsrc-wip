# $NetBSD: Makefile,v 1.6 2014/06/01 12:49:48 thomasklausner Exp $
#

DISTNAME=	rstudio-rstudio-v0.95.264-0-ge31bd49
PKGNAME=	rstudio-0.95.264
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	-https://github.com/rstudio/rstudio/tarball/v0.95.265

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/rstudio/rstudio/tarball/v0.95.265/
COMMENT=	Integrated Development Environment (IDE) for R
LICENSE=	gnu-agpl-v3

BUILD_DEPENDS+=		apache-ant-[0-9]*:../../devel/apache-ant
BUILD_DEPENDS+=		gwt-2.4.0:../../www/gwt
BUILD_DEPENDS+=		gin-1.5:../../wip/gin

# Force using "curl" for fetching the distribution file. It is only available
# over HTTPS and "curl" is the only fetch program which always supports HTTPS.

EXTRACT_USING=	gtar

WRKSRC=		${WRKDIR}/rstudio-rstudio-e31bd49
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DRSTUDIO_TARGET=Desktop
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Fix pathes
SUBST_FILES.path=	src/gwt/CMakeLists.txt
SUBST_SED.path+=	-e 's,COMMAND ant,COMMAND ${ANTDIR}/bin/ant,g'

post-patch:
	mkdir -p ${WRKSRC}/src/gwt/lib/gwt
	${LN} -s ${GWTDIR}/lib/java/gwt ${WRKSRC}/src/gwt/lib/gwt/2.4.0
	mkdir -p ${WRKSRC}/src/gwt/lib/gin
	${LN} -s ${GINDIR}/lib/java/gin ${WRKSRC}/src/gwt/lib/gin/1.5

.include "../../math/R/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/pangomm/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
