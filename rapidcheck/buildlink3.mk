# $NetBSD$

BUILDLINK_TREE+=	rapidcheck

.if !defined(RAPIDCHECK_BUILDLINK3_MK)
RAPIDCHECK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rapidcheck+=	rapidcheck>=0.0.0.20220314
BUILDLINK_PKGSRCDIR.rapidcheck?=	../../wip/rapidcheck
.endif	# RAPIDCHECK_BUILDLINK3_MK

BUILDLINK_TREE+=	-rapidcheck
