# $NetBSD: Makefile,v 1.6 2012/10/07 17:41:43 asau Exp $

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

INSTALLATION_DIRS=	${PKGMANDIR}/man1

SUBST_CLASSES+=		wish
SUBST_FILES.wish=	vkeybd.tcl
SUBST_STAGE.wish=	pre-build
SUBST_SED.wish=		-e 's,/usr/bin/wish,${PREFIX}/bin/wish,'

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
