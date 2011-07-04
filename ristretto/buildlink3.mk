# $NetBSD: buildlink3.mk,v 1.1 2011/07/04 13:48:36 reinoudz70 Exp $

BUILDLINK_TREE+=	ristretto

.if !defined(XFCE4_RISTRETTO_BUILDLINK3_MK)
XFCE4_RISTRETTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ristretto+=	ristretto>=0.0.93
BUILDLINK_PKGSRCDIR.ristretto?=	../../wip/ristretto

.endif # XFCE4_RISTRETTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-ristretto
