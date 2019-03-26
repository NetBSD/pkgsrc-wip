# $NetBSD$

BUILDLINK_TREE+=	laszip

.if !defined(LASZIP_BUILDLINK3_MK)
LASZIP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.laszip+=	laszip>=2.2.0
BUILDLINK_PKGSRCDIR.laszip?=	../../geography/laszip
.endif	# LASZIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-laszip
