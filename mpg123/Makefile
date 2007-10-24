# $NetBSD: Makefile,v 1.5 2007/10/24 07:45:48 bsadewitz Exp $
#

DISTNAME=	mpg123-snapshot-${MPG123_VERSION}
PKGREVISION=	1
CATEGORIES=	local
MASTER_SITES=	http://mpg123.orgis.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://mpg123.orgis.org/download/
COMMENT=        Command-line player for mpeg layer 1, 2 and 3 audio

CONFLICTS+=	mpg123{,nas,esound}-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes 		# XXX just barely! ;)
USE_TOOLS+=	pkg-config
USE_TOOLS+=	automake

WRKSRC=			${WRKDIR}/mpg123

SVN_REPOSITORIES=       mpg123
SVN_ROOT.mpg123=        svn://orgis.org/mpg123/trunk
SVN_MODULE.mpg123=      mpg123

#
# XXX need to convert various CPU-specific configurations from audio/mpg123
#
CONFIGURE_ARGS+=	--with-cpu=x86_dither
CFLAGS+=		-DDONT_CATCH_SIGNALS	# XXX very-alpha code AFAIK

PKGSRC_LIBLTDL=		${BUILDLINK_PREFIX.libltdl}/lib/libltdl.la

.include "../../wip/mk/svn-package.mk"

.include "../../mk/bsd.prefs.mk"
MPG123_VERSION!=${DATE} +%Y%m%d

#
# XXX Temporary workaround until the sun driver works on NetBSD (at least).
#
SUN=			${"${OPSYS:Msolaris}":?:\#}
SUBST_CLASSES+=		sun
SUBST_STAGE.sun=	pre-configure
SUBST_VARS.sun=		SUN
SUBST_FILES.sun=	src/output/Makefile.am
SUBST_MESSAGE.sun=	Enabling/disabling sun audio.

#
# XXX Why did I need to do this?
#
SUBST_CLASSES+=		ltdl
SUBST_STAGE.ltdl=	post-configure
SUBST_FILES.ltdl=	Makefile src/Makefile src/output/Makefile
SUBST_SED.ltdl=		-e 's,\-lltdl,${PKGSRC_LIBLTDL},'
SUBST_MESSAGE.ltdl=	Fixing libltdl brokenness.

pre-configure:
	cd ${WRKSRC} && autoreconf -v --install

.include "options.mk"

.include "../../devel/libltdl/convenience.mk"

.include "../../mk/bsd.pkg.mk"
