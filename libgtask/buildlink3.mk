# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/05/31 16:40:46 jihbed Exp $

BUILDLINK_TREE+=	libgtask

.if !defined(LIBGTASK_BUILDLINK3_MK)
LIBGTASK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgtask+=	libgtask>=0.1.2
BUILDLINK_PKGSRCDIR.libgtask?=	../../wip/libgtask


.include "../../devel/glib2/buildlink3.mk"

.endif	# LIBGTASK_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgtask
