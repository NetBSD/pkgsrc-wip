# $NetBSD: Makefile,v 1.3 2004/04/15 01:26:14 rockpiper Exp $

DISTNAME=	mpd-0.10.3
PKGNAME=	musicpd-0.10.3

CATEGORIES=	audio
MASTER_SITES=	http://mercury.chem.pitt.edu/~shank/

MAINTAINER=	pkg@burningsoda.com
HOMEPAGE=	http://www.musicpd.org/
COMMENT=	The Music Player Daemon allows remote access for playing music

USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

BUILD_DEFS+=	MUSICPD_WITH_FLAC\
		MUSICPD_WITH_OGG\
		MUSICPD_WITH_AUDIOFILE\
		MUSICPD_WITH_ICONV\
		MUSICPD_WITH_ID3\
		MUSICPD_WITH_OSSMIXER\
		MUSICPD_WITH_AAC\
		USE_INET6

MUSICPD_WITH_FLAC?= YES
MUSICPD_WITH_OGG?= YES
MUSICPD_WITH_AUDIOFILE?= YES
MUSICPD_WITH_ICONV?= YES
MUSICPD_WITH_ID3?= YES
MUSICPD_WITH_OSSMIXER?= YES
MUSICPD_WITH_AAC= YES

LDFLAGS+= ${LIBOSSAUDIO}

.include "../../mk/bsd.prefs.mk"

.if ${MUSICPD_WITH_FLAC} == "YES"
.include "../../audio/flac/buildlink3.mk"
CONFIGURE_ARGS+=--with-flac=${BUILDLINK_PREFIX.flac}
.else
CONFIGURE_ARGS+=--disable-flac
.endif

.if ${MUSICPD_WITH_OGG} == "YES"
.include "../../audio/libvorbis/buildlink3.mk"
CONFIGURE_ARGS+=--with-ogg=${BUILDLINK_PREFIX.libvorbis}
.else
CONFIGURE_ARGS+=--disable-ogg
.endif

.if ${MUSICPD_WITH_AUDIOFILE} == "YES"
.include "../../audio/libaudiofile/buildlink3.mk"
CONFIGURE_ARGS+=--with-audiofile=${BUILDLINK_PREFIX.audiofile}
.else
CONFIGURE_ARGS+=--disable-audiofile
.endif

.if ${MUSICPD_WITH_ICONV} == "YES"
.include "../../converters/libiconv/buildlink3.mk"
CONFIGURE_ARGS+=--with-iconv=${BUILDLINK_PREFIX.iconv}
.else
CONFIGURE_ARGS+=--disable-iconv
.endif

.if ${MUSICPD_WITH_ID3} == "YES"
.include "../../audio/libid3tag/buildlink3.mk"
CONFIGURE_ARGS+=--with-id3tag=${BUILDLINK_PREFIX.libid3tag}
.else
CONFIGURE_ARGS+=--disable-id3
.endif

.if ${MUSICPD_WITH_OSSMIXER} == "YES"
.include "../../mk/ossaudio.buildlink3.mk"
.else
CONFIGURE_ENV+=         NO_OSS_MIXER="YES"
MAKE_ENV+=              NO_OSS_MIXER="YES"
.endif

.if ${MUSICPD_WITH_AAC} == "YES"
.include "../../audio/faad2/buildlink3.mk"
CONFIGURE_ARGS+=--with-faad=${BUILDLINK_PREFIX.faad2}
.else
CONFIGURE_ARGS+=--disable-aac
.endif

.if defined(USE_INET6) && (${USE_INET6} == "YES")
CONFIGURE_ARGS+=--enable-ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif

pre-configure:
	cd ${WRKSRC}; ${AUTOCONF}

.include "../../mk/autoconf.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
