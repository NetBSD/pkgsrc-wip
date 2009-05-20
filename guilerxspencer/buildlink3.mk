# $NetBSD: buildlink3.mk,v 1.5 2009/05/20 00:58:41 thomasklausner Exp $

BUILDLINK_TREE+=	guilerxspencer

.if !defined(GUILERXSPENCER_BUILDLINK3_MK)
GUILERXSPENCER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.guilerxspencer+=	guilerxspencer>=1.2
BUILDLINK_ABI_DEPENDS.guilerxspencer?=	guilerxspencer>=1.2nb1
BUILDLINK_PKGSRCDIR.guilerxspencer?=	../../wip/guilerxspencer

.include "../../lang/guile/buildlink3.mk"
.endif # GUILERXSPENCER_BUILDLINK3_MK

BUILDLINK_TREE+=	-guilerxspencer
