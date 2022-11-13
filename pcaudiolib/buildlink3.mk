# $NetBSD: buildlink3.mk,v 1.19 2022/09/11 12:51:04 wiz Exp $

BUILDLINK_TREE+=	pcaudiolib

.if !defined(PCAUDIOLIB_BUILDLINK3_MK)
PCAUDIOLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pcaudiolib+=	pcaudiolib>=1.2
BUILDLINK_ABI_DEPENDS.pcaudiolib+=	pcaudiolib>=1.2
BUILDLINK_PKGSRCDIR.pcaudiolib?=	../../audio/pcaudiolib
BUILDLINK_INCDIRS.pcaudiolib?=		include/pcaudiolib

pkgbase:= pcaudiolib
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.pcaudiolib:Malsa}
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.pcaudiolib:Mpulseaudio}
.  include "../../audio/pulseaudio/buildlink3.mk"
.endif

.endif # PCAUDIOLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-pcaudiolib
