# $NetBSD: buildlink3.mk,v 1.8 2011/05/13 23:25:16 mwdavies Exp $

BUILDLINK_TREE+=	kdepimlibs

.if !defined(KDEPIMLIBS_BUILDLINK3_MK)
KDEPIMLIBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdepimlibs+=	kdepimlibs4>=4.0.0
BUILDLINK_ABI_DEPENDS.kdepimlibs?=	kdepimlibs4>=4.5.4nb1
BUILDLINK_PKGSRCDIR.kdepimlibs?=	../../wip/kdepimlibs4

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../wip/akonadi/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.endif # KDEPIMLIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdepimlibs
