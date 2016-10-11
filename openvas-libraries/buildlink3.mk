# $NetBSD$

BUILDLINK_TREE+=	openvas-libraries

.if !defined(OPENVAS_LIBRARIES_BUILDLINK3_MK)
OPENVAS_LIBRARIES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openvas-libraries+=	openvas-libraries>=8.0.8
BUILDLINK_PKGSRCDIR.openvas-libraries?=	../../wip/openvas-libraries

.include "../../databases/hiredis/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk";
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"
.include "../../security/libssh/buildlink3.mk"
.endif	# OPENVAS_LIBRARIES_BUILDLINK3_MK

BUILDLINK_TREE+=	-openvas-libraries
