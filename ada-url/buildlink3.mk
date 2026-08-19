# $NetBSD$

BUILDLINK_TREE+=	ada-url

.if !defined(ADA_URL_BUILDLINK3_MK)
ADA_URL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ada-url+=	ada-url>=3.0.0
BUILDLINK_PKGSRCDIR.ada-url?=	../../wip/ada-url
BUILDLINK_INCDIRS.ada-url?=	include
BUILDLINK_LIBDIRS.ada-url?=	lib

.endif	# ADA_URL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ada-url
