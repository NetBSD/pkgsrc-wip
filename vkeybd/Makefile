# $NetBSD: Makefile,v 1.4 2006/10/29 08:32:57 shattered Exp $

DISTNAME=	vkeybd-0.1.17
CATEGORIES=	audio
MASTER_SITES=	http://www.alsa-project.org/~iwai/

MAINTAINER=	oht@users.sourceforge.net
HOMEPAGE=	http://www.alsa-project.org/~iwai/
COMMENT=	Virtual midi keyboard

RAWMIDI=	/dev/rmidi0
WRKSRC=		${WRKDIR}/vkeybd
VKB_TCLFILE =	${PREFIX}/share/vkeybd/vkeybd.tcl
NO_CONFIGURE=	yes
CFLAGS+=	-Wall -O2
CFLAGS+=	-DVKB_TCLFILE=\"${VKB_TCLFILE:Q}\"
CFLAGS+=	-DVKB_USE_MIDI
CFLAGS+=	-DMIDI_DEV=\"${RAWMIDI:Q}\"

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
