# $NetBSD$

BUILDLINK_TREE+=	libstubborn

.if !defined(LIBSTUBBORN_BUILDLINK3_MK)
LIBSTUBBORN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libstubborn+=	libstubborn>=0.1
BUILDLINK_PKGSRCDIR.libstubborn?=	../../wip/libstubborn
.endif	# LIBSTUBBORN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libstubborn
