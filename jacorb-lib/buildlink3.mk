# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/11/29 17:57:27 daprice Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.JacORB-lib?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
JACORB_LIB_BUILDLINK3_MK:=	${JACORB_LIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	JacORB-lib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NJacORB-lib}
BUILDLINK_PACKAGES+=	JacORB-lib

.if !empty(JACORB_LIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.JacORB-lib+=	JacORB-lib>=1.4.1
BUILDLINK_PKGSRCDIR.JacORB-lib?=	../../wip/jacorb-lib
.endif	# JACORB_LIB_BUILDLINK3_MK

.include "../../lang/sun-jdk13/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
