# $NetBSD: buildlink3.mk,v 1.1 2013/05/25 13:05:56 francksys Exp $

BUILDLINK_TREE+=	info2man

.if !defined(INFO2MAN_BUILDLINK3_MK)
INFO2MAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.info2man+=	info2man>=20001101
BUILDLINK_PKGSRCDIR.info2man?=		../../wip/info2man
.endif	# INFO2MAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-info2man
