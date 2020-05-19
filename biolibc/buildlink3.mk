# $NetBSD$
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX

BUILDLINK_TREE+=	biolibc

.if !defined(BIOLIBC_BUILDLINK3_MK)
BIOLIBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.biolibc+=	biolibc>=0.1.0.16
BUILDLINK_PKGSRCDIR.biolibc?=	../../wip/biolibc
BUILDLINK_DEPMETHOD.biolibc?=	build
.endif	# BIOLIBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-biolibc
