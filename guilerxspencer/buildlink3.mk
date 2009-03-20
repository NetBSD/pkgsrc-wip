# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:42 jsonn Exp $

BUILDLINK_TREE+=	guilerxspencer

BUILDLINK_API_DEPENDS.guilerxspencer+=	guilerxspencer>=1.2
BUILDLINK_PKGSRCDIR.guilerxspencer?=	../../wip/guilerxspencer

.include "../../lang/guile/buildlink3.mk"
.endif # GUILERXSPENCER_BUILDLINK3_MK

BUILDLINK_TREE+=	-guilerxspencer
