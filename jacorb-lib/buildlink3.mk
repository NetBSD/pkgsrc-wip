# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:43 jsonn Exp $
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

BUILDLINK_TREE+=	JacORB-lib

BUILDLINK_API_DEPENDS.JacORB-lib+=	JacORB-lib>=1.4.1
BUILDLINK_PKGSRCDIR.JacORB-lib?=	../../wip/jacorb-lib

.include "../../lang/sun-jdk13/buildlink3.mk"
.endif # JACORB_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-JacORB-lib
