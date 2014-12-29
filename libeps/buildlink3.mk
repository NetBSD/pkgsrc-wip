# $NetBSD: buildlink3.mk,v 1.1 2014/12/29 19:14:53 nros Exp $
#

BUILDLINK_TREE+=	libeps

.if !defined(LIBEPS_BUILDLINK3_MK)
LIBEPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libeps+=	libeps>=1.7
BUILDLINK_PKGSRCDIR.libeps?=	../../wip/libeps
.endif	# LIBEPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libeps
