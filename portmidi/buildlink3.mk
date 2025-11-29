# $NetBSD$

BUILDLINK_TREE+=	portmidi

.if !defined(PORTMIDI_BUILDLINK3_MK)
PORTMIDI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.portmidi+=	portmidi>=2.0.4
BUILDLINK_PKGSRCDIR.portmidi?=		../../wip/portmidi
.endif	# PORTMIDI_BUILDLINK3_MK

BUILDLINK_TREE+=	-portmidi
