# $NetBSD$

BUILDLINK_TREE+=	muparser

.if !defined(MUPARSER_BUILDLINK3_MK)
MUPARSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.muparser+=	muparser>=2.2.6.1
BUILDLINK_PKGSRCDIR.muparser?=		../../wip/muparser
.endif	# MUPARSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-muparser
