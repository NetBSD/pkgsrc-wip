# $NetBSD: buildlink3.mk,v 1.12 2008/03/14 20:37:53 netcap Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
AUDACIOUS_BUILDLINK3_MK:=	${AUDACIOUS_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	audacious
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Naudacious}
BUILDLINK_PACKAGES+=	audacious
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}audacious

.if ${AUDACIOUS_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.audacious+=	audacious>=1.5.0
BUILDLINK_PKGSRCDIR.audacious?=	../../wip/audacious
BUILDLINK_DEPMETHOD.audacious?=	build
.endif	# AUDACIOUS_BUILDLINK3_MK

.include "../../wip/mowgli/buildlink3.mk"
.include "../../devel/libmcs/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
