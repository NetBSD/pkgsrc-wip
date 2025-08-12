# $NetBSD$

BUILDLINK_TREE+=	pipewire

.if !defined(PIPEWIRE_BUILDLINK3_MK)
PIPEWIRE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pipewire+=	pipewire>=1.2.5
BUILDLINK_PKGSRCDIR.pipewire?=	../../multimedia/pipewire

.endif	# PIPEWIRE_BUILDLINK3_MK

BUILDLINK_TREE+=	-pipewire
