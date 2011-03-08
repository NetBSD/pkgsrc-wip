# $NetBSD: buildlink3.mk,v 1.1 2011/03/08 10:48:53 jihbed Exp $

BUILDLINK_TREE+=	libginac

.if !defined(LIBGINAC_BUILDLINK3_MK)
LIBGINAC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libginac+=	libginac>=1.5.8
BUILDLINK_PKGSRCDIR.libginac?=	../../wip/libginac

.include "../../devel/readline/buildlink3.mk"
.include "../../math/cln/buildlink3.mk"
.endif	# LIBGINAC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libginac
