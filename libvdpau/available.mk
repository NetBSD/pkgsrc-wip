# $NetBSD: available.mk,v 1.1 2010/07/23 22:50:34 cheusov Exp $

.include "../../mk/bsd.prefs.mk"

# At the moment VDPAU is available only for Linux, FreeBSD and
# [Open]Solaris.  The following condition is here to NOT list these
# platforms in multiple places, i.e. in mplayer, xine, xbmc etc.
# Have a look at buildlink3.mk too.
.if (${OPSYS} == "Linux" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "SunOS")
VDPAU_AVAILABLE=	yes
.else
VDPAU_AVAILABLE=	no
.endif
