# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:52 jsonn Exp $
#

BUILDLINK_TREE+=	sj3-client

.if !defined(SJ3_CLIENT_BUILDLINK3_MK)
SJ3_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sj3-client+=	sj3-client>=2.0.1.23
BUILDLINK_PKGSRCDIR.sj3-client?=	../../wip/sj3-client
.endif # SJ3_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-sj3-client
