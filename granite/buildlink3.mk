# $NetBSD$

BUILDLINK_TREE+=	granite

.if !defined(GRANITE_BUILDLINK3_MK)
GRANITE_BUILDLINK3_MK:=


BUILDLINK_DEPMETHOD.granite?=	build

BUILDLINK_API_DEPENDS.granite+=	granite>=7.1.0
BUILDLINK_PKGSRCDIR.granite?=	../../wip/granite


.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.endif	# GRANITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-granite
