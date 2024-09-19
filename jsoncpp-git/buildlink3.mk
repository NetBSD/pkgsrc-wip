# $NetBSD: buildlink3.mk,v 1.1 2014/04/18 22:27:54 thomasklausner Exp $

BUILDLINK_TREE+=	jsoncpp

.if !defined(JSONCPP_BUILDLINK3_MK)
JSONCPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jsoncpp+=	jsoncpp>=0.6.0rc2nb20140216
BUILDLINK_PKGSRCDIR.jsoncpp?=	../../wip/jsoncpp-git
BUILDLINK_DEPMETHOD.jsoncpp?=	build
.endif	# JSONCPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-jsoncpp
