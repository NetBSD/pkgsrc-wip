# $NetBSD$

BUILDLINK_TREE+=	double-conversion

.if !defined(DOUBLE-CONVERSION_BUILDLINK3_MK)
DOUBLE-CONVERSION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.double-conversion+=	double-conversion>=3.0.0
BUILDLINK_ABI_DEPENDS.double-conversion+=	double-conversion>=3.0.0
BUILDLINK_PKGSRCDIR.double-conversion?=	../../wip/double-conversion

.endif # DOUBLE-CONVERSION_BUILDLINK3_MK

BUILDLINK_TREE+=	-double-conversion
