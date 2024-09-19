# $NetBSD: buildlink3.mk,v 1.17 2018/08/16 18:54:28 adam Exp $

BUILDLINK_TREE+=	minizip192


BUILDLINK_PKGSRCDIR.minizip-git?=	../../wip/minizip192

.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/cmake/buildlink3.mk"

BUILDLINK_TREE+=	-minizip192
