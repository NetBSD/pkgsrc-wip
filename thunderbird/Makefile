# $NetBSD: Makefile,v 1.6 2009/11/27 15:48:04 tnn2 Exp $
#

DISTNAME=	thunderbird-${TB_VER}.source
PKGNAME=	thunderbird-${TB_VER}
TB_VER=		3.0rc1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA:=thunderbird/releases/${TB_VER}/source/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mozillamessaging.com/en-US/thunderbird/
COMMENT=	Organize, secure and customize your mail

WRKSRC=		${WRKDIR}/comm-1.9.1
MOZILLA_DIR=	mozilla/

CONFIG_GUESS_OVERRIDE+=	directory/c-sdk/config/autoconf/config.guess
CONFIG_SUB_OVERRIDE+=	directory/c-sdk/config/autoconf/config.sub

CONFIGURE_ARGS+=	--enable-application=mail
CONFIGURE_ARGS+=	--enable-static

# XXX these should be options, but for now ...
CONFIGURE_ARGS+=	--disable-dbus --disable-gnomevfs --disable-gnomeui
CONFIGURE_ARGS+=	--disable-jit

ALL_ENV+=		MOZILLA_PKG_NAME=thunderbird

# Unfortunately thunderbird doesn't support building with external libxul-sdk
# yet. I don't feel like replicating all of the xulrunner patches in wip,
# so let's just reach over with a quick and dirty hack.
# They will apply cleanly as long as xulrunner and thunderbird are based
# on the same gecko minor release. I expect they will usually be due to the
# way mozilla releases security updates.
post-extract:
	cd ${WRKSRC}/${MOZILLA_DIR} &&					\
	  cat ${.CURDIR}/../../devel/xulrunner/patches/patch-* |	\
	  ${TOOLS_PLATFORM.patch} -p0

pre-configure:
	cd ${WRKSRC}/directory/c-sdk && ${SETENV} ${CONFIGURE_ENV} autoconf
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoconf
	cd ${WRKSRC}/mozilla && ${SETENV} ${CONFIGURE_ENV} autoconf
	cd ${WRKSRC}/mozilla/js/src && ${SETENV} ${CONFIGURE_ENV} autoconf
	cd ${WRKSRC}/mozilla/nsprpub && ${SETENV} ${CONFIGURE_ENV} autoconf
	cd ${WRKSRC}/directory/c-sdk && ${SETENV} ${CONFIGURE_ENV} autoconf

do-build:
# XXX for some reason it doesn't work unless -j is explicitly specified
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} -j${MAKE_JOBS:U1}

.include "../../devel/xulrunner/mozilla-common.mk"
.include "../../mk/bsd.pkg.mk"
