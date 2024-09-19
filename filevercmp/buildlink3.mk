# $NetBSD$

BUILDLINK_TREE+=	filevercmp

.if !defined(FILEVERCMP_BUILDLINK3_MK)
FILEVERCMP_BUILDLINK3_MK:=
BUILDLINK_DEPMETHOD.filevercmp?=	build

BUILDLINK_API_DEPENDS.filevercmp+=	filevercmp>=0.0.0.20151117
BUILDLINK_PKGSRCDIR.filevercmp?=	../../wip/filevercmp
.endif	# FILEVERCMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-filevercmp
