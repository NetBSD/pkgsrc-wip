# $NetBSD$

BUILDLINK_TREE+=	transient

.if !defined(TRANSIENT_BUILDLINK3_MK)
TRANSIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.transient+=	${EMACS_PKGNAME_PREFIX}transient-[0-9]*
BUILDLINK_PKGSRCDIR.transient?=		../../wip/transient

BUILDLINK_CONTENTS_FILTER.transient+=	${EGREP} '.*\.el$$|.*\.elc$$'

.endif

BUILDLINK_TREE+=	-transient
