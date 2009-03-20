# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:52 jsonn Exp $

BUILDLINK_TREE+=	tagsoup

.if !defined(TAGSOUP_BUILDLINK3_MK)
TAGSOUP_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.tagsoup?=	build
BUILDLINK_API_DEPENDS.tagsoup+=	tagsoup>=0.6
BUILDLINK_PKGSRCDIR.tagsoup?=	../../wip/tagsoup
.endif # TAGSOUP_BUILDLINK3_MK

BUILDLINK_TREE+=	-tagsoup
