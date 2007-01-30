# $NetBSD: buildlink3.mk,v 1.1 2007/01/30 03:20:59 bsadewitz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PULSEAUDIO_BUILDLINK3_MK:=	${PULSEAUDIO_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	pulseaudio
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npulseaudio}
BUILDLINK_PACKAGES+=	pulseaudio
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}pulseaudio

.if ${PULSEAUDIO_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.pulseaudio+=	pulseaudio>=0.9.5
BUILDLINK_PKGSRCDIR.pulseaudio?=	../../wip/pulseaudio
.endif	# PULSEAUDIO_BUILDLINK3_MK

# XXX What goes here?  They don't like explaining these things, do they ...
.include "../../devel/liboil/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
#.include "../../audio/jack/buildlink3.mk"
#.include "../../x11/libXt/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
