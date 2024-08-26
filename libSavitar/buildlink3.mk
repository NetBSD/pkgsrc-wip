# $NetBSD$

BUILDLINK_TREE+=	libSavitar

.if !defined(LIBSAVITAR_BUILDLINK3_MK)
LIBSAVITAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libSavitar+=	libSavitar>=4.11.0
BUILDLINK_PKGSRCDIR.libSavitar?=	../../wip/libSavitar

BUILDLINK_DEPMETHOD.py-sip4?=	build

.include "../../wip/py-sip4/buildlink3.mk"
.endif	# LIBSAVITAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libSavitar
