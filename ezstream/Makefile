# $NetBSD: Makefile,v 1.5 2012/12/04 00:40:08 othyro Exp $
#

DISTNAME=	ezstream-0.5.6
CATEGORIES=	audio
MASTER_SITES=	http://downloads.us.xiph.org/releases/ezstream/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.icecast.org/ezstream.php
COMMENT=	Streamming client of mp3 and oggvorbis for icecast
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c c++ fortran
USE_TOOLS+=		pkg-config

.include "options.mk"

.include "../../audio/libshout/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
