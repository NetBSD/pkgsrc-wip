# $NetBSD: buildlink3.mk,v 1.1 2012/11/11 11:12:53 zul_ Exp $

BUILDLINK_TREE+=	girara

.if !defined(GIRARA_BUILDLINK3_MK)
GIRARA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.girara+=	girara>=0.1.4
BUILDLINK_ABI_DEPENDS.girara+=	girara>=0.1.4
BUILDLINK_PKGSRCDIR.girara?=	../../wip/girara

.include "../../x11/gtk2/buildlink3.mk"
.endif # GIRARA_BUILDLINK3_MK

BUILDLINK_TREE+=	-girara
