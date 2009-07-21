# $NetBSD: buildlink3.mk,v 1.1 2009/07/21 07:30:43 koifren Exp $

BUILDLINK_TREE+=	taglib-extras

.if !defined(TAGLIB_EXTRAS_BUILDLINK3_MK)
TAGLIB_EXTRAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.taglib-extras+=	taglib-extras>=0.1.4
BUILDLINK_PKGSRCDIR.taglib-extras?=	../../wip/taglib-extras

.include "../../audio/taglib/buildlink3.mk"
.endif	# TAGLIB_EXTRAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-taglib-extras
