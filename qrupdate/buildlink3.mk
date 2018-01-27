# $NetBSD$
BUILDLINK_TREE+=	qrupdate

.if !defined(QRUPDATE_BUILDLINK3_MK)
QRUPDATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qrupdate+=	qrupdate>=1.1.2
BUILDLINK_PKGSRCDIR.qrupdate?=		../../wip/qrupdate
.endif	# QRUPDATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qrupdate
