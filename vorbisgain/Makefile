# $NetBSD: Makefile,v 1.1.1.1 2004/09/09 19:53:57 goteki Exp $

DISTNAME=		vorbisgain-0.34
CATEGORIES=		audio
MASTER_SITES=		http://sjeng.org/ftp/vorbis/
EXTRACT_SUFX=		.zip

MAINTAINER=		goteki@users.sourceforge.net
HOMEPAGE=		http://sjeng.org/vorbisgain.html
COMMENT=		ReplayGain technology for Vorbis

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make

EXTRACT_CMD_OPTS.zip=   -aqo

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

