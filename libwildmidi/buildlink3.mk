# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/08/01 02:29:45 pallegra Exp $

BUILDLINK_TREE+=	libwildmidi

.if !defined(LIBWILDMIDI_BUILDLINK3_MK)
LIBWILDMIDI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwildmidi+=	libwildmidi>=0.2.3.4
BUILDLINK_PKGSRCDIR.libwildmidi?=	../../wip/libwildmidi
.endif	# LIBWILDMIDI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwildmidi
