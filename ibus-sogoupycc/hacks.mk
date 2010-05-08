# $NetBSD: hacks.mk,v 1.1.1.1 2010/05/08 09:48:22 obache Exp $

.if !defined(IBUS_SOGOUPYCC_HACK_MK)
IBUS_SOGOUPYCC_HACK_MK=	# empty

# XXX dumped
BUILDLINK_TRANSFORM+=	rm:-O[1-9]*

.endif
