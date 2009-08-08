# $NetBSD: buildlink3.mk,v 1.8 2009/08/08 05:36:12 obache Exp $

BUILDLINK_TREE+=	scim

.if !defined(SCIM_BUILDLINK3_MK)
SCIM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.scim+=	scim>=1.4.7
BUILDLINK_PKGSRCDIR.scim?=	../../wip/scim

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # SCIM_BUILDLINK3_MK

BUILDLINK_TREE+=	-scim
