# $Id: volume_id.mk,v 1.3 2008/11/22 14:57:20 thomasklausner Exp $
# from "Id: oshavercd.mk,v 1.4 2003/11/19 21:28:47 bubuchka Exp"
#
#
# The following system variables must be defined before:
#	VOLUME_ID_PC				libvolume_id.pc file
#
# The following variables will be defined:
#	OS_HAVE_VOLUME_ID			YES, if OS have libvolume_id.pc, or NO elsewhere

.if !defined(OSVOLUME_ID_MK)
OSVOLUME_ID_MK=		# defined

.include "../../mk/bsd.prefs.mk"

OS_PKG_CONFIG_LIBDIR?=		/usr/lib/pkgconfig
VOLUME_ID_PC?=			${OS_PKG_CONFIG_LIBDIR}/libvolume_id.pc
OS_HAVE_VOLUME_ID=		NO


.if (${OPSYS} == "Linux") && exists(${VOLUME_ID_PC})
OS_HAVE_VOLUME_ID=		YES
.	if !empty(USE_TOOLS:Mpkg-config)
_PKG_CONFIG_LIBDIR?=		${BUILDLINK_DIR}/lib/pkgconfig:${BUILDLINK_DIR}/share/pkgconfig:${OS_PKG_CONFIG_LIBDIR}
.	endif
.else
. 	include "../../devel/libvolume_id/buildlink3.mk"
.endif

.endif	# OSVOLUME_ID_MK
