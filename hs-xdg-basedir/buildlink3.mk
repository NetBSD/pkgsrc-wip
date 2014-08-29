# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:10:30 szptvlfn Exp $

BUILDLINK_TREE+=	hs-xdg-basedir

.if !defined(HS_XDG_BASEDIR_BUILDLINK3_MK)
HS_XDG_BASEDIR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-xdg-basedir+=	hs-xdg-basedir>=0.2.1
BUILDLINK_ABI_DEPENDS.hs-xdg-basedir+=	hs-xdg-basedir>=0.2.1
BUILDLINK_PKGSRCDIR.hs-xdg-basedir?=	../../wip/hs-xdg-basedir
.endif	# HS_XDG_BASEDIR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-xdg-basedir
