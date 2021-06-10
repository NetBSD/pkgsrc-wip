# $NetBSD: buildlink3.mk,v 1.2 2020/11/05 17:06:10 bacon Exp $

BUILDLINK_TREE+=	openblas64_pthread

.if !defined(OPENBLAS64_PTHREAD_BUILDLINK3_MK)
OPENBLAS64_PTHREAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openblas64_pthread+=	openblas64_pthread>=0.3.5
BUILDLINK_PKGSRCDIR.openblas64_pthread?=	../../wip/openblas64_pthread
.endif	# OPENBLAS64_PTHREAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-openblas64_pthread
