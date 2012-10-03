# $NetBSD: Makefile,v 1.3 2012/10/03 15:09:58 asau Exp $
#

DISTNAME=	mpg123-0.65
CATEGORIES=	audio
MASTER_SITES=	http://www.mpg123.de/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://www.mpg123.de/
COMMENT=	Command line player for MPEG layer 1, 2, and 3 audio
LICENSE=	mpg123-license

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-optimization=4
CONFIGURE_ARGS+=	--with-audio=sun
CONFIGURE_ARGS+=	--with-audio=oss
.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--with-cpu=i386_fpu
#CONFIGURE_ARGS+=	--with-cpu=i586_dither  # If you use i386, play with
#CONFIGURE_ARGS+=	--with-cpu=mmx		# these.
.else
CONFIGURE_ARGS+=	--with-cpu=generic_fpu
.endif

CONFIGURE_ARGS+=	LIBS="-lossaudio"

CONFIGURE_ENV+=	CFLAGS=${MPG_CFLAGS:M*:Q}

CPPFLAGS+=	-DDEVOSSAUDIO=\"${DEVOSSAUDIO:Q}\"
CPPFLAGS+=	-DDEVOSSSOUND=\"${DEVOSSSOUND:Q}\"

.include "../../mk/oss.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
