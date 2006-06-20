# $NetBSD: Makefile,v 1.1.1.1 2006/06/20 18:20:21 gschwarz Exp $
#

DISTNAME=	speex-1.1.12
PKGNAME=	${DISTNAME:S,speex,speex-devel,}
CATEGORIES=	audio
MASTER_SITES=	http://downloads.us.xiph.org/releases/speex/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.speex.org/
COMMENT=	Open-source, patent-free voice codec
# files derived from audio/speex, which is the non-development version

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	speex.pc.in
USE_TOOLS+=		pkg-config

# previous versions of the package were called Speex
# conflicts with the non-development version
CONFLICTS=	Speex-[0-9]* speex-[0-9]*

CONFIGURE_ARGS+=	--with-ogg-dir="${BUILDLINK_PREFIX.libogg}"

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE:Q}

BUILDLINK_TRANSFORM+=	l:gnugetopt:getopt

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
