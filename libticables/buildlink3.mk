# $NetBSD: buildlink3.mk,v 1.1 2004/03/28 07:09:19 bjan2 Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.libticables?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBTICABLES_BUILDLINK3_MK:=	${LIBTICABLES_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libticables
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibticables}
BUILDLINK_PACKAGES+=	libticables

.if !empty(LIBTICABLES_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libticables+=	libticables>=3.7.6
BUILDLINK_PKGSRCDIR.libticables?=	../../wip/libticables
.endif	# LIBTICABLES_BUILDLINK3_MK

.include "../../devel/libusb/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
