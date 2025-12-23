# $NetBSD$

BUILDLINK_TREE+=	plasma6-kpipewire

.if !defined(PLASMA6_KPIPEWIRE_BUILDLINK3_MK)
PLASMA6_KPIPEWIRE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.plasma6-kpipewire+=	plasma6-kpipewire>=6.5.2
BUILDLINK_PKGSRCDIR.plasma6-kpipewire?=		../../wip/plasma6-kpipewire

.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/libepoxy/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../multimedia/ffmpeg7/buildlink3.mk"
.include "../../multimedia/libva/buildlink3.mk"
.include "../../wip/pipewire/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# PLASMA6_KPIPEWIRE_BUILDLINK3_MK

BUILDLINK_TREE+=	-plasma6-kpipewire
