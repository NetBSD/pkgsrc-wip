# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/05/14 11:11:02 obache Exp $
#

BUILDLINK_TREE+=	wordcut

.if !defined(WORDCUT_BUILDLINK3_MK)
WORDCUT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wordcut+=	wordcut>=0.5.1b2
BUILDLINK_PKGSRCDIR.wordcut?=	../../wip/wordcut
.endif	# WORDCUT_BUILDLINK3_MK

BUILDLINK_TREE+=	-wordcut
