# $NetBSD: buildlink3.mk,v 1.2 2013/06/17 12:45:10 thomasklausner Exp $

BUILDLINK_TREE+=	boo

.if !defined(BOO_BUILDLINK3_MK)
BOO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.boo+=	boo>=0.9.4.9
BUILDLINK_ABI_DEPENDS.boo?=	boo>=0.9.4.9nb1
BUILDLINK_PKGSRCDIR.boo?=	../../wip/boo

.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../lang/mono2/buildlink3.mk"
.endif	# BOO_BUILDLINK3_MK

BUILDLINK_TREE+=	-boo
