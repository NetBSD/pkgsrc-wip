# $NetBSD$

BUILDLINK_TREE+=	frida-libffi

.if !defined(FRIDA_LIBFFI_BUILDLINK3_MK)
FRIDA_LIBFFI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.frida-libffi+=	frida-libffi>=3.0.13
BUILDLINK_PKGSRCDIR.frida-libffi?=	../../wip/frida-libffi
.endif	# FRIDA_LIBFFI_BUILDLINK3_MK

BUILDLINK_TREE+=	-frida-libffi
