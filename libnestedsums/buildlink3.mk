# $NetBSD: buildlink3.mk,v 1.1 2012/09/05 12:40:16 jihbed Exp $

BUILDLINK_TREE+=	libnestedsums

.if !defined(LIBNESTEDSUMS_BUILDLINK3_MK)
LIBNESTEDSUMS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnestedsums+=	libnestedsums>=1.4.12
BUILDLINK_PKGSRCDIR.libnestedsums?=	../../wip/nestedsums


.include "../../wip/libginac/buildlink3.mk"
.endif	# LIBNESTEDSUMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnestedsums
