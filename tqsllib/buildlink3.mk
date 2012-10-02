# $NetBSD: buildlink3.mk,v 1.1 2012/10/02 15:29:55 makoto Exp $

BUILDLINK_TREE+=	tqsllib

.if !defined(TQSLLIB_BUILDLINK3_MK)
TQSLLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tqsllib+=	tqsllib>=2.2
BUILDLINK_PKGSRCDIR.tqsllib=	../../wip/tqsllib
.endif # TQSLLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-tqsllib
