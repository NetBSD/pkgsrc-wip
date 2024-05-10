# $NetBSD$

BUILDLINK_TREE+=	freetds

.if !defined(FREETDS_BUILDLINK3_MK)
FREETDS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freetds+=	freetds>=1.4
BUILDLINK_PKGSRCDIR.freetds?=	../../wip/freetds

.include "../../converters/libiconv/buildlink3.mk"

pkgbase := freetds
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.freetds:Mgnutls}
.  include "../../security/gnutls/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.freetds:Mopenssl}
.  include "../../security/openssl/buildlink3.mk"
.endif
.endif # FREETDS_BUILDLINK3_MK

BUILDLINK_TREE+=	-freetds
