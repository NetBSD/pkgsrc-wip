# $NetBSD$

BUILDLINK_TREE+=	opensubdiv

.if !defined(OPENSUBDIV_BUILDLINK3_MK)
OPENSUBDIV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opensubdiv+=	opensubdiv>=3.4.4
BUILDLINK_PKGSRCDIR.opensubdiv?=	../../wip/opensubdiv
.endif	# OPENSUBDIV_BUILDLINK3_MK

BUILDLINK_TREE+=	-opensubdiv
