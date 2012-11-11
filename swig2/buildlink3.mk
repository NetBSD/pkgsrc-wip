# $NetBSD: buildlink3.mk,v 1.3 2012/11/11 22:24:02 outpaddling Exp $

BUILDLINK_TREE+=	swig2

.if !defined(SWIG_BUILDLINK3_MK)
SWIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.swig2+=	swig>=2.0.8
BUILDLINK_PKGSRCDIR.swig2?=	../../devel/swig2

.include "../../devel/pcre/buildlink3.mk"
.endif	# SWIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-swig2
