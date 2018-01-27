# $NetBSD: buildlink3.mk,v 1.1 2013/11/07 03:04:59 makoto Exp $
#
BUILDLINK_TREE+=	git_modes

.if !defined(GIT_MODES_BUILDLINK3_MK)
GIT_MODES_BUILDLINK3_MK:=
BUILDLINK_API_DEPENDS.git_modes?=	git-modes-git-[0-9]*
BUILDLINK_PKGSRCDIR.git_modes?=		../../wip/git-modes-git

BUILDLINK_CONTENTS_FILTER.git_modes=	${EGREP} '.*\.el$$|.*\.elc$$'

.endif # GIT_MODES_BUILDLINK3_MK

BUILDLINK_TREE+=	-git_modes
