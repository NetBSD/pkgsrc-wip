# $NetBSD: buildlink3.mk,v 1.1 2014/06/07 09:34:26 thomasklausner Exp $

BUILDLINK_TREE+=	libffi

.if !defined(LIBFFI_BUILDLINK3_MK)
LIBFFI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libffi+=	libffi>=1.20
BUILDLINK_ABI_DEPENDS.libffi+=	libffi>=3.0.11
BUILDLINK_PKGSRCDIR.libffi?=	../../wip/libffi
.endif # LIBFFI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libffi
