# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:43:43 jsonn Exp $

BUILDLINK_TREE+=	hxt

.if !defined(HXT_BUILDLINK3_MK)
HXT_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hxt?=	build
BUILDLINK_API_DEPENDS.hxt+=	hxt>=8.2.0
BUILDLINK_PKGSRCDIR.hxt?=	../../wip/hxt

.include "../../wip/HUnit/buildlink3.mk"
.include "../../wip/hs-curl/buildlink3.mk"
.include "../../wip/hs-network/buildlink3.mk"
.include "../../wip/hs-parallel/buildlink3.mk"
.include "../../wip/parsec/buildlink3.mk"
.include "../../wip/tagsoup/buildlink3.mk"
.endif # HXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hxt
