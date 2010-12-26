# $NetBSD: buildlink3.mk,v 1.7 2010/12/26 05:01:23 davesainty Exp $

BUILDLINK_TREE+=	synfig

.if !defined(SYNFIG_BUILDLINK3_MK)
SYNFIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.synfig+=	synfig>=0.61.08
BUILDLINK_ABI_DEPENDS.synfig?=	synfig>=0.61.08
BUILDLINK_PKGSRCDIR.synfig?=	../../wip/synfig

pkgbase:= synfig
.  include "../../mk/pkg-build-options.mk"

.  if !empty(PKG_BUILD_OPTIONS.synfig:Mpng)
.    include "../../graphics/png/buildlink3.mk"
.  endif

.  if !empty(PKG_BUILD_OPTIONS.synfig:Mmng)
.    include "../../graphics/mng/buildlink3.mk"
.  endif

.  if !empty(PKG_BUILD_OPTIONS.synfig:Mjpeg)
.    include "../../mk/jpeg.buildlink3.mk"
.  endif

.  if !empty(PKG_BUILD_OPTIONS.synfig:Mfreetype)
.    include "../../graphics/freetype2/buildlink3.mk"
.  endif

.  if !empty(PKG_BUILD_OPTIONS.synfig:Mfontconfig)
.    include "../../fonts/fontconfig/buildlink3.mk"
.  endif

.  if !empty(PKG_BUILD_OPTIONS.synfig:Mopenexr)
.    include "../../graphics/openexr/buildlink3.mk"
.  endif

.  if !empty(PKG_BUILD_OPTIONS.synfig:Mlavcodec)
.    include "../../multimedia/ffmpeg/buildlink3.mk"
.  endif

.include "../../devel/ETL/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../textproc/libxml++/buildlink3.mk"
.endif # SYNFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-synfig
