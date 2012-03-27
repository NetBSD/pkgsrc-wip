# $NetBSD: buildlink3.mk,v 1.2 2012/03/27 17:48:00 outpaddling Exp $

BUILDLINK_TREE+=	swig

.if !defined(SWIG_BUILDLINK3_MK)
SWIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.swig+=	swig>=2.0.4
BUILDLINK_PKGSRCDIR.swig?=	../../wip/swig2

.include "../../devel/pcre/buildlink3.mk"
.endif	# SWIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-swig
