# $NetBSD: Makefile,v 1.9 2012/11/13 20:39:10 othyro Exp $

DISTNAME=	mpg123-${MPG123_VERSION}
CATEGORIES=	audio

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://www.mpg123.de
COMMENT=	Mpg123 MPEG layer 1, 2, 3 audio player
LICENSE=	mpg123-license

NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

USE_TOOLS+=		automake autoreconf date perl pkg-config
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

WRKSRC=			${WRKDIR}/mpg123

CONFIGURE_ARGS+=	--with-optimization=3
CONFIGURE_ARGS+=	--with-audio=sun
.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--with-cpu=x86
.elif ${MACHINE_ARCH} == "macppc"
CONFIGURE_ARGS+=	--with-cpu=altivec # I'll add options soon for this.
.endif

CHECK_BUILTIN.oss:=yes
.include "../../mk/oss.builtin.mk"
CHECK_BUILTIN.oss:=no

.if !empty(USE_BUILTIN.oss:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-audio=oss
CONFIGURE_ARGS+=	LIBS=${BUILDLINK_LDADD.oss:Q}

.include "../../mk/oss.buildlink3.mk"
.endif

CPPFLAGS+=		-DDEVOSSAUDIO=\"${DEVOSSAUDIO}\"
CPPFLAGS+=		-DDEVOSSSOUND=\"${DEVOSSSOUND}\"

SVN_REPOSITORIES=	mpg123
#SVN_TAG=		{${MPG123_TAG}}
SVN_REPO.mpg123=	svn://orgis.org/mpg123/trunk

pre-configure:
	cd ${WRKSRC} && autoreconf -iv

.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.fast.prefs.mk"

#YESTERDAY!=		expr `date +%s` - 86399
#MPG123_VERSION!=	${DATE} -r ${YESTERDAY} +%Y%m%d
#MPG123_TAG!=		${DATE} +%Y%m%d

.include "../../mk/bsd.pkg.mk"
