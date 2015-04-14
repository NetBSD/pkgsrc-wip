# $NetBSD: buildlink3.mk,v 1.3 2015/04/14 18:09:40 leot1990 Exp $

BUILDLINK_TREE+=	girara

.if !defined(GIRARA_BUILDLINK3_MK)
GIRARA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.girara+=	girara>=0.2.4
BUILDLINK_ABI_DEPENDS.girara+=	girara>=0.2.4
BUILDLINK_PKGSRCDIR.girara?=	../../wip/girara

.include "../../x11/gtk3/buildlink3.mk"
.endif # GIRARA_BUILDLINK3_MK

BUILDLINK_TREE+=	-girara
