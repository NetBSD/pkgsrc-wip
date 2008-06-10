# $NetBSD: buildlink3.mk,v 1.2 2008/06/10 09:21:26 tnn2 Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
FIREFOX_BUILDLINK3_MK:=	${FIREFOX_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=		firefox
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nfirefox}
BUILDLINK_PACKAGES+=	firefox
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}firefox

.if !empty(FIREFOX_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.firefox+=	firefox>=3.0rc1
BUILDLINK_PKGSRCDIR.firefox?=	../../wip/firefox
# XXX wip
GECKO_EXTRA_INC_DIRS= \
  . caps chardet commandhandler content docshell dom downloads exthandler \
  fastfind gfx gtkembedmoz intl js layout mimetype necko pipboot pipnss \
  shistory uriloader webbrowserpersist webbrwsr widget windowwatcher xpcom \
  xpconnect

GECKO_EXTRA_INCLUDE=	${GECKO_EXTRA_INC_DIRS:C,^,-I${BUILDLINK_PREFIX.firefox}/include/firefox/,}
.endif	# FIREFOX_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
