# $NetBSD$

BUILDLINK_TREE+=	biolibc

.if !defined(BIOLIBC_BUILDLINK3_MK)
BIOLIBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.biolibc+=	biolibc>=0.2.4.5
BUILDLINK_PKGSRCDIR.biolibc?=	../../wip/biolibc

.include "../../wip/libxtend/buildlink3.mk"
.endif	# BIOLIBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-biolibc
