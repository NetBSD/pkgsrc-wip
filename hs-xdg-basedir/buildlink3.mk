# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/08 10:03:04 phonohawk Exp $

BUILDLINK_TREE+=	hs-xdg-basedir

.if !defined(HS_XDG_BASEDIR_BUILDLINK3_MK)
HS_XDG_BASEDIR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-xdg-basedir+=	hs-xdg-basedir>=0.2
BUILDLINK_PKGSRCDIR.hs-xdg-basedir?=	../../wip/hs-xdg-basedir
.endif	# HS_XDG_BASEDIR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-xdg-basedir
