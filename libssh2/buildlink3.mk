# $NetBSD: buildlink3.mk,v 1.5 2008/01/18 04:30:15 tnn2 Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBSSH2_BUILDLINK3_MK:=	${LIBSSH2_BUILDLINK3_MK}+

.include "../../mk/bsd.fast.prefs.mk"

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libssh2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibssh2}
BUILDLINK_PACKAGES+=	libssh2
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libssh2

.if ${LIBSSH2_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libssh2+=	libssh2>=0.17
BUILDLINK_ABI_DEPENDS.libssh2?=	libssh2>=0.17nb1
BUILDLINK_PKGSRCDIR.libssh2?=	../../wip/libssh2

pkgbase:=	libssh2
.include "../../mk/pkg-build-options.mk"

.endif	# LIBSSH2_BUILDLINK3_MK

.if !empty(PKG_BUILD_OPTIONS.libssh2:Mssl)
.	include "../../security/openssl/buildlink3.mk"
.elif !empty(PKG_BUILD_OPTIONS.libssh2:Mlibgcrypt)
.	include "../../security/libgcrypt/buildlink3.mk"
.endif

.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
