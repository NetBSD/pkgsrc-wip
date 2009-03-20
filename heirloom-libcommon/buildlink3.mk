# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:42 jsonn Exp $

BUILDLINK_TREE+=	heirloom-libcommon

.if !defined(HEIRLOOM_LIBCOMMON_BUILDLINK3_MK)
HEIRLOOM_LIBCOMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.heirloom-libcommon+=	heirloom-libcommon>=070227
BUILDLINK_PKGSRCDIR.heirloom-libcommon?=	../../wip/heirloom-libcommon
BUILDLINK_DEPMETHOD.heirloom-libcommon?=	build
BUILDLINK_INCDIRS.heirloom-libcommon+=		include/heirloom
.endif # HEIRLOOM_LIBCOMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-heirloom-libcommon
