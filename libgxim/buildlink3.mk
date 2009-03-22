# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/03/22 16:14:10 jihbed Exp $
BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBGXIM_BUILDLINK3_MK:=	${LIBGXIM_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libgxim
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgxim}
BUILDLINK_PACKAGES+=	libgxim
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libgxim

.if ${LIBGXIM_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libgxim+=	libgxim>=0.3.1
BUILDLINK_PKGSRCDIR.libgxim?=	../../category/libgxim
.endif	# LIBGXIM_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
