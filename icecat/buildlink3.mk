# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:43 jsonn Exp $

BUILDLINK_TREE+=	icecat

.if !defined(ICECAT_BUILDLINK3_MK)
ICECAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.icecat+=		icecat>=3.0
BUILDLINK_PKGSRCDIR.icecat?=		../../wip/icecat
# XXX wip
GECKO_EXTRA_INC_DIRS= \
  . caps chardet commandhandler content docshell dom downloads exthandler \
  fastfind gfx gtkembedmoz intl js layout mimetype necko pipboot pipnss \
  shistory uriloader webbrowserpersist webbrwsr widget windowwatcher xpcom \
  xpconnect

GECKO_EXTRA_INCLUDE=	${GECKO_EXTRA_INC_DIRS:C,^,-I${BUILDLINK_PREFIX.icecat}/include/icecat/,}
.endif # ICECAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-icecat
