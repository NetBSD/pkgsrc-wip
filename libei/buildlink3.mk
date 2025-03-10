# $NetBSD$

BUILDLINK_TREE+=	libei

.if !defined(LIBEI_BUILDLINK3_MK)
LIBEI_BUILDLINK3_MK:=

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_API_DEPENDS.libei+=	libei>=1.4.0
BUILDLINK_PKGSRCDIR.libei?=	../../wip/libei
#BUILDLINK_PKGSRCDIR.libei?=	../../x11/libei

.if defined(OPSYS_HAS_KQUEUE)
.include "../../devel/libepoll-shim/buildlink3.mk"
.endif
.endif	# LIBEI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libei
