# $Id: alsa.mk,v 1.2 2012/11/07 03:07:09 othyro Exp $
# from "Id: oshavercd.mk,v 1.4 2003/11/19 21:28:47 bubuchka Exp"
#
#
# The following system variables must be defined before:
#	ALSA_PC				alsa.pc file
#
# The following variables will be defined:
#	OS_HAVE_ALSA			YES, if OS have rc.d, or NO elsewhere

.ifndef OSHAVEALSA_MK
OSHAVEALSA_MK=		# defined

.include "../../mk/bsd.prefs.mk"

ALSA_PC?=		/usr/lib/pkgconfig/alsa.pc

.include "../../mk/buildlink3/bsd.builtin.mk"


.if ${OPSYS} == "Linux"
.	if exists(${ALSA_PC})

OS_HAVE_ALSA=		YES
BUILDLINK_TARGETS+=	buildlink-alsa

.PHONY: buildlink-alsa
buildlink-alsa:
	${MKDIR} ${BUILDLINK_DIR}/lib/pkgconfig/
	${LN} -s ${ALSA_PC} ${BUILDLINK_DIR}/lib/pkgconfig/

.	else
OS_HAVE_ALSA=		NO
.include "../../audio/alsa-lib/buildlink3.mk"
.	endif
.endif

.endif	# OSHAVEALSA_MK
