# $NetBSD: buildlink2.mk,v 1.1 2004/02/11 01:40:57 bjan2 Exp $

.if !defined(COIN_BUILDLINK2_MK)
COIN_BUILDLINK2_MK=		#defined

BUILDLINK_PACKAGES+=		Coin
BUILDLINK_PKGBASE.Coin=		Coin
BUILDLINK_DEPENDS.Coin?=	Coin>=2.2.1
BUILDLINK_PKGSRCDIR.Coin?=	../../wip/Coin

EVAL_PREFIX+=			BUILDLINK_PREFIX.Coin=Coin
BUILDLINK_PREFIX.Coin_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.Coin+=		include/Inventor/*.h
BUILDLINK_FILES.Coin+=		include/Inventor/C/*.h
BUILDLINK_FILES.Coin+=		include/Inventor/C/base/*.h
BUILDLINK_FILES.Coin+=		include/Inventor/C/errors/*.h
BUILDLINK_FILES.Coin+=		include/Inventor/C/glue/*.h
BUILDLINK_FILES.Coin+=		include/Inventor/C/threads/*.h
BUILDLINK_FILES.Coin+=		include/Inventor/VRMLnodes/*.h
BUILDLINK_FILES.Coin+=		include/Inventor/actions/*.h
BUILDLINK_FILES.Coin+=		include/Inventor/annex/HardCopy/*.h
BUILDLINK_FILES.Coin+=		include/Inventor/bundles/*.h
BUILDLINK_FILES.Coin+=		include/Inventor/caches/*.h
BUILDLINK_FILES.Coin+=		include/Inventor/collision/*.h
BUILDLINK_FILES.Coin+=		include/Inventor/details/*.h
BUILDLINK_FILES.Coin+=		include/Inventor/draggers/*.h
BUILDLINK_FILES.Coin+=		include/Inventor/elements/*.h
BUILDLINK_FILES.Coin+=		include/Inventor/engines/*.h
BUILDLINK_FILES.Coin+=		include/Inventor/errors/*.h
BUILDLINK_FILES.Coin+=		include/Inventor/events/*.h
BUILDLINK_FILES.Coin+=		include/Inventor/fields/*.h
BUILDLINK_FILES.Coin+=		include/Inventor/lists/*.h
BUILDLINK_FILES.Coin+=		include/Inventor/lock/*.h
BUILDLINK_FILES.Coin+=		include/Inventor/manips/*.h
BUILDLINK_FILES.Coin+=		include/Inventor/misc/*.h
BUILDLINK_FILES.Coin+=		include/Inventor/nodekits/*.h
BUILDLINK_FILES.Coin+=		include/Inventor/nodes/*.h
BUILDLINK_FILES.Coin+=		include/Inventor/projectors/*.h
BUILDLINK_FILES.Coin+=		include/Inventor/sensors/*.h
BUILDLINK_FILES.Coin+=		include/Inventor/system/*.h
BUILDLINK_FILES.Coin+=		include/Inventor/threads/*.h

BUILDLINK_FILES.Coin+=	lib/libCoin.*

BUILDLINK_TARGETS+=		Coin-buildlink

Coin-buildlink: _BUILDLINK_USE
.endif # COIN_BUILDLINK2_MK
