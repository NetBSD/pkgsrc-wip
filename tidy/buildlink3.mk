# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:25:38 joerg Exp $

BUILDLINK_TREE+=	tidy

.if !defined(TIDY_BUILDLINK3_MK)
TIDY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tidy+=	tidy>=5.1.25
BUILDLINK_PKGSRCDIR.tidy?=	../../wip/tidy
.endif # TIDY_BUILDLINK3_MK

BUILDLINK_TREE+=	-tidy
