# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:39 jsonn Exp $

BUILDLINK_TREE+=	MissingH

.if !defined(MISSINGH_BUILDLINK3_MK)
MISSINGH_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.MissingH?=	build
BUILDLINK_API_DEPENDS.MissingH+=	MissingH>=1.0.2.1
BUILDLINK_PKGSRCDIR.MissingH?=	../../wip/MissingH

.include "../../wip/hslogger/buildlink3.mk"
.endif # MISSINGH_BUILDLINK3_MK

BUILDLINK_TREE+=	-MissingH
