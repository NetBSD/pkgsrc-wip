# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:24:57 joerg Exp $

BUILDLINK_TREE+=	blis_pthread

.if !defined(BLIS_PTHREAD_BUILDLINK3_MK)
BLIS_PTHREAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.blis_pthread+=	blis_pthread>=0.9.0
BUILDLINK_ABI_DEPENDS.blis_pthread+=	blis_pthread>=0.9.0
BUILDLINK_PKGSRCDIR.blis_pthread?=	../../wip/blis_pthread
.endif # BLIS_PTHREAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-blis_pthread
