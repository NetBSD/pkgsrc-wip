# $NetBSD: Makefile,v 1.2 2008/02/25 16:18:05 shattered Exp $

DISTNAME=		ocp-0.1.15
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		http://stian.lunafish.org/ocp/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://stian.lunafish.org/project-ocp.php
COMMENT=		Open Cubic Player

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake makeinfo
USE_LANGUAGES=		c c++
USE_NCURSES=		yes	# resize_term
INFO_FILES=		yes

CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/info

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
