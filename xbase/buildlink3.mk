# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:53 jsonn Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.2.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.

BUILDLINK_TREE+=	xbase

BUILDLINK_API_DEPENDS.xbase+=	xbase>=2.0.0
BUILDLINK_PKGSRCDIR.xbase?=	../../wip/xbase
.endif # XBASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-xbase
