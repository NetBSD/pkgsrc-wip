# $NetBSD: buildlink3.mk,v 1.2 2004/03/17 12:03:07 mpasternak Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.3.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GLIB2_BUILDLINK3_MK:=	${GLIB2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	glib2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nglib2}
BUILDLINK_PACKAGES+=	glib2

.if !empty(GLIB2_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.glib2+=	glib2>=2.4.0
BUILDLINK_PKGSRCDIR.glib2?=	../../wip/glib2-devel

.include "../../mk/bsd.prefs.mk"

.ifdef GLIB_USE_GNU_ICONV
_BUILDLINK_GLIB_USE_GNU_ICONV=		${GLIB_USE_GNU_ICONV}
.else
_BUILDLINK_GLIB_USE_GNU_ICONV=		no
.endif

.if ${OPSYS} == "FreeBSD"
_BUILDLINK_GLIB_USE_GNU_ICONV=		no
.endif

.if ${_BUILDLINK_GLIB_USE_GNU_ICONV} == [Nn][Oo]
CONFIGURE_ARGS+=	--with-libiconv=native
.else
CONFIGURE_ARGS+=	--with-libiconv=gnu
.include "../../devel/gettext-lib/buildlink3.mk"
.endif

.endif	# GLIB2_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
