# $NetBSD: Makefile,v 1.4 2006/12/23 13:56:16 cetrox Exp $
#

DISTNAME=	ffmpeg-export-snapshot
PKGNAME=        ffmpeg-snapshot-${VERSION}
CATEGORIES=	multimedia
MASTER_SITES=	http://ffmpeg.mplayerhq.hu/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ccatrian@eml.cc
HOMEPAGE=	http://ffmpeg.mplayerhq.hu/
COMMENT=	Nightly snapshot of the ffmpeg tool

WRKSRC=		${WRKDIR}/${SRCDIR}
HAS_CONFIGURE=	yes
NO_CHECKSUM=	yes

CONFIGURE_ARGS+=	--enable-gpl
CONFIGURE_ARGS+=	--enable-memalign-hack
CONFIGURE_ARGS+=	--enable-swscaler
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=        --prefix=${PREFIX}

CONFLICTS+=	ffmpeg-devel-[0-9]*
CONFLICTS+=	ffmpeg-[0-9]*

REPLACE_PERL+=	doc/texi2pod.pl

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

CONF_FILES=	${PREFIX}/share/examples/ffmpeg/ffserver.conf \
		${PKG_SYSCONFDIR}/ffserver.conf

.include "../../mk/bsd.prefs.mk"

TODAY!=         ${DATE} -u +%Y-%m-%d

.if exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
# Fetch the date of the snapshot from file
.  if ${OPSYS} != "DragonFly"
DISTDATE!=      tar jtf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
                2>/dev/null | head -1 | cut -f 3-5 -d "-";
.  else
DISTDATE!=	gtar ytf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		2>/dev/null | head -1 | cut -f 3-5 -d "-";
.  endif
.else
DISTDATE=       ${TODAY}
.endif

.include "options.mk"

# Appends today's date to the build
SRCDIR=         ffmpeg-export-${TODAY}
VERSION!=       ${ECHO} ${TODAY} | ${SED} -e "s/-//g"

# Checking if distfile is recent.
.if empty(PKG_OPTIONS:Mold-dist)
post-fetch:
	@if [ -f ${DISTDIR}/${DISTFILES:Q} ]; then \
	  if [ ${DISTDATE} = ${TODAY} ]; then \
		${PHASE_MSG} "Distfile is from today." ; \
	  else \
		${ECHO} "Distfile is dated from ${DISTDATE}." ; \
		${ECHO} "Please cleandir and fetch distfile again," ; \
		${ECHO} "or set PKG_OPTIONS.ffmpeg-snapshot=old-dist\
		option to build anyway." ; \
		exit 1; \
	  fi \
	fi
.endif

.include "../../mk/bsd.pkg.mk"
