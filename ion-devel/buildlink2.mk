# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/04/03 09:27:17 cubidou Exp $

.if !defined(ION_BUILDLINK2_MK)
ION_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		ion
BUILDLINK_DEPENDS.ion?=		ion>=20030327
BUILDLINK_PKGSRCDIR.ion?=	../../local/ion-devel

EVAL_PREFIX+=			BUILDLINK_PREFIX.ion=ion
BUILDLINK_PREFIX.ion_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.ion=		include/ion/*.h
BUILDLINK_FILES.ion+=		include/ion/*.mk
BUILDLINK_FILES.ion+=		include/ion/ioncore/*.h
BUILDLINK_FILES.ion+=		include/libtu/*
BUILDLINK_FILES.ion+=		lib/libtu.a

BUILDLINK_TARGETS+=		ion-buildlink

ion-buildlink: _BUILDLINK_USE

.endif	# ION_BUILDLINK2_MK
