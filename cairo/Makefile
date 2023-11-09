# $NetBSD: Makefile,v 1.154 2023/01/29 21:14:37 ryoon Exp $

.include "../../wip/cairo/Makefile.common"

TEST_TARGET=			check

MESON_ARGS+=	-Dglib=disabled

PKGCONFIG_OVERRIDE_STAGE=       post-build
PKGCONFIG_OVERRIDE+=		output/meson-private/*.pc

.include "options.mk"

.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
# include?
#.include "../../print/libspectre/buildlink3.mk"
BUILDLINK_API_DEPENDS.pixman+=	pixman>=0.36.0
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
