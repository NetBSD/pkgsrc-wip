# $NetBSD: buildlink3.mk,v 1.2 2007/12/24 08:18:09 mwdavies Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
KDELIBS_BUILDLINK3_MK:=	${KDELIBS_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	kdelibs
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nkdelibs}
BUILDLINK_PACKAGES+=	kdelibs
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}kdelibs

.if ${KDELIBS_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.kdelibs+=	kdelibs>=3.96.1
BUILDLINK_PKGSRCDIR.kdelibs?=	../../wip/kdelibs4
.endif	# KDELIBS_BUILDLINK3_MK

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../wip/strigi/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../net/mDNSResponder/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/fam.buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/enchant/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
