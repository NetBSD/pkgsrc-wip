# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:53 jsonn Exp $

BUILDLINK_TREE+=	wvstreams

.if !defined(WVSTREAMS_BUILDLINK3_MK)
WVSTREAMS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wvstreams+=	wvstreams>=4.5.1
BUILDLINK_PKGSRCDIR.wvstreams?=		../../wip/wvstreams
.endif # WVSTREAMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-wvstreams
