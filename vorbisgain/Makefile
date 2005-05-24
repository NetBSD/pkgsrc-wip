# $NetBSD: Makefile,v 1.3 2005/05/24 10:31:48 rillig Exp $

DISTNAME=		vorbisgain-0.34
CATEGORIES=		audio
MASTER_SITES=		http://sjeng.org/ftp/vorbis/
EXTRACT_SUFX=		.zip

MAINTAINER=		goteki@users.sourceforge.net
HOMEPAGE=		http://sjeng.org/vorbisgain.html
COMMENT=		ReplayGain technology for Vorbis

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

EXTRACT_CMD_OPTS.zip=   -aqo

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

