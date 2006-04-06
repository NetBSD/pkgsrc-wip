# $NetBSD: buildlink3.mk,v 1.2 2006/04/06 07:17:20 jeremy-c-reed Exp $

BUILDLINK_DEPTH:=				${BUILDLINK_DEPTH}+
JACK_AUDIO_CONNECTION_KIT_BUILDLINK3_MK:=	${JACK_AUDIO_CONNECTION_KIT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	jack-audio-connection-kit
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Njack-audio-connection-kit}
BUILDLINK_PACKAGES+=	jack-audio-connection-kit

.if !empty(JACK_AUDIO_CONNECTION_KIT_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.jack-audio-connection-kit+=	jack-audio-connection-kit>=0.100.0
BUILDLINK_PKGSRCDIR.jack-audio-connection-kit?=	../../wip/jack
.endif	# JACK_AUDIO_CONNECTION_KIT_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
