# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/12/09 12:24:28 yhardy Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
ICECAT_BUILDLINK3_MK:=		${ICECAT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=		icecat
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nicecat}
BUILDLINK_PACKAGES+=	icecat
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}icecat

.if !empty(ICECAT_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.icecat+=		icecat>=3.0
BUILDLINK_PKGSRCDIR.icecat?=		../../wip/icecat
# XXX wip
GECKO_EXTRA_INC_DIRS= \
  . caps chardet commandhandler content docshell dom downloads exthandler \
  fastfind gfx gtkembedmoz intl js layout mimetype necko pipboot pipnss \
  shistory uriloader webbrowserpersist webbrwsr widget windowwatcher xpcom \
  xpconnect

GECKO_EXTRA_INCLUDE=	${GECKO_EXTRA_INC_DIRS:C,^,-I${BUILDLINK_PREFIX.icecat}/include/icecat/,}
.endif	# ICECAT_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
