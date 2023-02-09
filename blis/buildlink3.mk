# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:24:57 joerg Exp $

BUILDLINK_TREE+=	blis

.if !defined(BLIS_BUILDLINK3_MK)
BLIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.blis+=	blis>=0.9.0
BUILDLINK_ABI_DEPENDS.blis+=	blis>=0.9.0
BUILDLINK_PKGSRCDIR.blis?=	../../wip/blis
.endif # BLIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-blis
