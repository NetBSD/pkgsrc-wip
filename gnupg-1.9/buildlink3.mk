# $NetBSD: buildlink3.mk,v 1.4 2004/10/14 22:31:01 johnrshannon Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.7.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.gnupg2?=	build

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GNUPG2_BUILDLINK3_MK:=	${GNUPG2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnupg2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnupg2}
BUILDLINK_PACKAGES+=	gnupg2

.if !empty(GNUPG2_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnupg2+=	gnupg2>=1.9.11
BUILDLINK_PKGSRCDIR.gnupg2?=	../../wip/gnupg-1.9
.endif	# GNUPG2_BUILDLINK3_MK

.include "../../wip/libgpg-error/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../wip/libassuan/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"
.include "../../wip/pinentry/buildlink3.mk"
.include "../../wip/dirmngr/buildlink3.mk"
.include "../../devel/pth/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
