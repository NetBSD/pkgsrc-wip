# $NetBSD: buildlink3.mk,v 1.4 2014/08/29 14:10:28 szptvlfn Exp $

BUILDLINK_TREE+=	hs-simple-sendfile

.if !defined(HS_SIMPLE_SENDFILE_BUILDLINK3_MK)
HS_SIMPLE_SENDFILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-simple-sendfile+=	hs-simple-sendfile>=0.2.13
BUILDLINK_ABI_DEPENDS.hs-simple-sendfile+=	hs-simple-sendfile>=0.2.13
BUILDLINK_PKGSRCDIR.hs-simple-sendfile?=	../../wip/hs-simple-sendfile

.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_SIMPLE_SENDFILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-simple-sendfile
