# $NetBSD$

BUILDLINK_TREE+=	libsignal-protocol-c

.if !defined(LIBSIGNAL_PROTOCOL_C_BUILDLINK3_MK)
LIBSIGNAL_PROTOCOL_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsignal-protocol-c+=	libsignal-protocol-c>=2.3.3
BUILDLINK_PKGSRCDIR.libsignal-protocol-c?=	../../wip/libsignal-protocol-c
.endif	# LIBSIGNAL_PROTOCOL_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsignal-protocol-c
