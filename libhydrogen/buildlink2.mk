BUILDLINK_PACKAGES+=			libhydrogen
BUILDLINK_PKGBASE.libhydrogen=		libhydrogen
BUILDLINK_DEPENDS.libhydrogen?=		libhydrogen>=0.8.0
BUILDLINK_PKGSRCDIR.libhydrogen?=	../../audio/libhydrogen

EVAL_PREFIX+=				BUILDLINK_PREFIX.libhydrogen=libhydrogen
BUILDLINK_PREFIX.libhydrogen_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libhydrogen=		include/hydrogen/*.h
BUILDLINK_FILES.libhydrogen+=		lib/libhydrogen.*

BUILDLINK_TARGETS+=           libhydrogen-buildlink

.include "../../audio/libaudiofile/buildlink2.mk"

libhydrogen-buildlink: _BUILDLINK_USE
