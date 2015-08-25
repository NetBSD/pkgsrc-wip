# $NetBSD: buildlink3.mk,v 1.2 2015/08/25 13:41:23 leot1990 Exp $

BUILDLINK_TREE+=	espeak

.if !defined(ESPEAK_BUILDLINK3_MK)
ESPEAK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.espeak+=	espeak>=1.48
BUILDLINK_PKGSRCDIR.espeak?=	../../audio/espeak

.include "../../audio/portaudio/buildlink3.mk"
.endif # ESPEAK_BUILDLINK3_MK

BUILDLINK_TREE+=	-espeak
