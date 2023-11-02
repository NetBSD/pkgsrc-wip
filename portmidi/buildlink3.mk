# $NetBSD$
# XXX
# XXX This file was created automatically using createbuildlink-3.19.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.

BUILDLINK_TREE+=	portmidi

.if !defined(PORTMIDI_BUILDLINK3_MK)
PORTMIDI_BUILDLINK3_MK:=

# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.portmidi?=	build

BUILDLINK_API_DEPENDS.portmidi+=	portmidi>=2.0.4
BUILDLINK_PKGSRCDIR.portmidi?=	../../wip/portmidi
.endif	# PORTMIDI_BUILDLINK3_MK

BUILDLINK_TREE+=	-portmidi
