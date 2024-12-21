# $NetBSD$

BUILDLINK_TREE+=	mpdecimal

.if !defined(MPDECIMAL_BUILDLINK3_MK)
MPDECIMAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpdecimal+=	mpdecimal>=4.0.0
BUILDLINK_PKGSRCDIR.mpdecimal?=	../../wip/mpdecimal
.endif	# MPDECIMAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpdecimal
