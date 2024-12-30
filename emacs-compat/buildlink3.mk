# $NetBSD$

BUILDLINK_TREE+=	emacs-compat

.if !defined(EMACS_COMPAT_BUILDLINK3_MK)
EMACS_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.emacs-compat+=	emacs-compat-[0-9]*
BUILDLINK_PKGSRCDIR.emacs-compat?=	../../wip/emacs-compat

BUILDLINK_CONTENTS_FILTER.emacs-compat+=	${EGREP} '.*\.el$$|.*\.elc$$'

.endif

BUILDLINK_TREE+=	-emacs-compat
