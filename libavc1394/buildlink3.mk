# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:44 jsonn Exp $

BUILDLINK_TREE+=	libavc1394

BUILDLINK_API_DEPENDS.libavc1394+=	libavc1394>=0.4.1
BUILDLINK_PKGSRCDIR.libavc1394?=	../../wip/libavc1394

.include "../../wip/libraw1394/buildlink3.mk"
.endif # LIBAVC1394_BUILDLINK3_MK

BUILDLINK_TREE+=	-libavc1394
