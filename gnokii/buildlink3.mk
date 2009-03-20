# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:41 jsonn Exp $

BUILDLINK_TREE+=	gnokii

.if !defined(GNOKII_BUILDLINK3_MK)
GNOKII_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnokii+=	gnokii>=0.6.14
BUILDLINK_PKGSRCDIR.gnokii?=	../../wip/gnokii

.include "../../devel/libusb/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.endif # GNOKII_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnokii
