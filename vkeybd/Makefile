# $NetBSD: Makefile,v 1.1.1.1 2005/02/13 18:44:33 oht Exp $

DISTNAME=	vkeybd-0.1.17
CATEGORIES=	audio
MASTER_SITES=	http://www.alsa-project.org/~iwai/

MAINTAINER=	oht@users.sourceforge.net
HOMEPAGE=   	http://www.alsa-project.org/~iwai/
COMMENT=	Virtual midi keyboard

R?=		0
RAWMIDI=	"\\\"/dev/rmidi${R}\\\""
WRKSRC=         ${WRKDIR}/vkeybd
VKB_TCLFILE =	"\\\"${PREFIX}/share/vkeybd/vkeybd.tcl\\\""
NO_CONFIGURE=   yes
CFLAGS+= -Wall -O2 -DVKB_TCLFILE=${VKB_TCLFILE} \
 	-DVKB_USE_MIDI -DMIDI_DEV=${RAWMIDI}
USE_BUILDLINK3= yes

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
