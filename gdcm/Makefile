# $NetBSD$

DISTNAME=	gdcm-${PKGVERSION}
PKGVERSION=	3.0.10
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gdcm/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	stix@stix.id.au
HOMEPAGE=	https://gdcm.sourceforge.net/
COMMENT=	Grassroots DiCoM for processing DICOM medical files
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config
CMAKE_CONFIGURE_ARGS+=	-DGDCM_USE_SYSTEM_ZLIB=ON
CMAKE_CONFIGURE_ARGS+=	-DGDCM_USE_SYSTEM_OPENSSL=ON
CMAKE_CONFIGURE_ARGS+=	-DGDCM_USE_SYSTEM_EXPAT=ON
CMAKE_CONFIGURE_ARGS+=	-DGDCM_USE_SYSTEM_OPENJPEG=ON
CMAKE_CONFIGURE_ARGS+=	-DGDCM_INSTALL_MAN_DIR=man
CMAKE_CONFIGURE_ARGS+=	-DGDCM_MANPAGES_USE_NONET:BOOL=TRUE

TOOL_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen

SUBST_CLASSES+=		docbook
SUBST_MESSAGE.docbook=	Fix docbook URLs.
SUBST_FILES.docbook=	Utilities/doxygen/man/*.xml
SUBST_STAGE.docbook=	pre-configure
SUBST_SED.docbook+=	-e 's,http://docbook.sourceforge.net/release/xsl-ns/current,${PREFIX}/share/xsl/docbook,g'

.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxslt/xsltproc-nonet.mk"
.include "../../mk/bsd.pkg.mk"
