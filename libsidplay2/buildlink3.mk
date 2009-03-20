# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:48 jsonn Exp $
#

BUILDLINK_TREE+=	libsidplay

.if !defined(LIBSIDPLAY_BUILDLINK3_MK)
LIBSIDPLAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsidplay+=	libsidplay>=20060528
BUILDLINK_PKGSRCDIR.libsidplay?=	../../wip/libsidplay2
.endif # LIBSIDPLAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsidplay
