# $NetBSD: buildlink3.mk,v 1.3 2008/07/20 16:26:16 phonohawk Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SYNFIG_BUILDLINK3_MK:=	${SYNFIG_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	synfig
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsynfig}
BUILDLINK_PACKAGES+=	synfig
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}synfig

.if ${SYNFIG_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.synfig+=	synfig>=0.61.08
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
.    include "../../graphics/jpeg/buildlink3.mk"
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

.endif	# SYNFIG_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../textproc/libxml++/buildlink3.mk"
.include "../../wip/ETL/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
