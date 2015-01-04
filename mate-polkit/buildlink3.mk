# $NetBSD: buildlink3.mk,v 1.1 2015/01/04 01:25:55 obache Exp $
#

BUILDLINK_TREE+=	mate-polkit

.if !defined(MATE_POLKIT_BUILDLINK3_MK)
MATE_POLKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mate-polkit+=	mate-polkit>=1.8.0
BUILDLINK_PKGSRCDIR.mate-polkit?=	../../wip/mate-polkit

.include "../../wip/polkit/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif	# MATE_POLKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mate-polkit
