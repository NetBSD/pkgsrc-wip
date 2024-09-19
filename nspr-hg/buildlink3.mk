# $NetBSD: buildlink3.mk,v 1.2 2014/09/28 14:16:55 thomasklausner Exp $

BUILDLINK_TREE+=	nspr

.if !defined(NSPR_BUILDLINK3_MK)
NSPR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nspr+=	nspr>=4.10
BUILDLINK_PKGSRCDIR.nspr?=	../../wip/nspr-hg

BUILDLINK_FILES.nspr+=		lib/nspr/*
BUILDLINK_FILES.nspr+=		include/nspr/*
BUILDLINK_FILES.nspr+=		include/nspr/obsolete/*

BUILDLINK_LIBDIRS.nspr+=	lib/nspr
BUILDLINK_RPATHDIRS.nspr+=	lib/nspr

BUILDLINK_INCDIRS.nspr+=	include/nspr

.endif	# NSPR_BUILDLINK3_MK

BUILDLINK_TREE+=	-nspr
