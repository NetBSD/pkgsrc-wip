# $NetBSD: buildlink3.mk,v 1.4 2009/05/06 09:34:13 cheusov Exp $

BUILDLINK_TREE+=	libavc1394

.if !defined(LIBAVC1394_BUILDLINK3_MK)
LIBAVC1394_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libavc1394+=	libavc1394>=0.4.1
BUILDLINK_PKGSRCDIR.libavc1394?=	../../wip/libavc1394

.include "../../wip/libraw1394/buildlink3.mk"
.endif # LIBAVC1394_BUILDLINK3_MK

BUILDLINK_TREE+=	-libavc1394
