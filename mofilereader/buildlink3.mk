# $NetBSD$

BUILDLINK_TREE+=	mofilereader

.if !defined(MOFILEREADER_BUILDLINK3_MK)
MOFILEREADER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mofilereader+=	mofilereader>=1.2.0
BUILDLINK_ABI_DEPENDS.mofilereader+=	mofilereader>=1.2.0
BUILDLINK_PKGSRCDIR.mofilereader?=	../../wip/mofilereader
.endif

BUILDLINK_TREE+=	-mofilereader
