# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/06/22 02:49:15 phonohawk Exp $

BUILDLINK_TREE+=	sox

.if !defined(SOX_BUILDLINK3_MK)
SOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sox+=	sox>=14.2.0
BUILDLINK_PKGSRCDIR.sox?=	../../wip/sox

.endif	# SOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-sox
