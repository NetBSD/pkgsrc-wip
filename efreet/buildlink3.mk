# $NetBSD: buildlink3.mk,v 1.9 2010/01/18 09:38:19 thomasklausner Exp $

BUILDLINK_TREE+=	efreet

.if !defined(EFREET_BUILDLINK3_MK)
EFREET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.efreet+=	efreet>=0.5.0.062
BUILDLINK_ABI_DEPENDS.efreet?=	efreet>=0.5.0.062nb3
BUILDLINK_PKGSRCDIR.efreet?=	../../wip/efreet

.include        "../../wip/ecore/buildlink3.mk"
.endif # EFREET_BUILDLINK3_MK

BUILDLINK_TREE+=	-efreet
