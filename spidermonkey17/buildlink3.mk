# $NetBSD: buildlink3.mk,v 1.4 2015/04/10 18:29:00 krytarowski Exp $

BUILDLINK_TREE+=	spidermonkey17

.if !defined(SPIDERMONKEY17_BUILDLINK3_MK)
SPIDERMONKEY17_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spidermonkey17+=	spidermonkey17>=17.0.0
BUILDLINK_PKGSRCDIR.spidermonkey17?=	../../wip/spidermonkey17

.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif	# SPIDERMONKEY17_BUILDLINK3_MK

BUILDLINK_TREE+=	-spidermonkey17
