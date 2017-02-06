# $NetBSD$

DISTNAME=	Argyll_V1.8.3_src
CATEGORIES=	graphics
MASTER_SITES=	http://www.argyllcms.com/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.argyllcms.com/
COMMENT=	ICC compatible color management system
LICENSE=	gnu-agpl-v3

WRKSRC=		${WRKDIR}/Argyll_V1.8.3
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	png/libpng.pc.in
PKGCONFIG_OVERRIDE+=	tiff/libtiff-4.pc.in
PKGCONFIG_OVERRIDE+=	xml/mxml.pc.in
PKGCONFIG_OVERRIDE+=	zlib/zlib.pc.in

BUILDLINK_TRANSFORM+=	rm:-ldl

DEPENDS+=	jam-[0-9]*:../../devel/jam

#post-patch:
#	@${REINPLACE_CMD} 's:711:755:g' ${WRKSRC}/Jambase

do-build:
	@cd ${WRKSRC} && ${MAKE_ENV} jam -q -fJambase -j${MAKE_JOBS}

do-install:
	@cd ${WRKSRC} && ${SETENV} DESTDIR=${STAGEDIR} PREFIX=${PREFIX} \
		REFSUBDIR=share/argyll/ref \
		jam -q -fJambase -j${MAKE_JOBS_NUMBER} install
	@${MV} ${STAGEDIR}${PREFIX}/bin/License.txt \
		${STAGEDIR}${PREFIX}/share/argyll/

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/xineramaproto/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
