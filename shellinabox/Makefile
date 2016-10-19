# $NetBSD$

PKGBASE=        shellinabox
DISTNAME=       ${PKGBASE}-v2.19
PKGREVISION=    1
CATEGORIES=     www

MASTER_SITES=   ${MASTER_SITE_GITHUB:=shellinabox/}
GITHUB_PROJECT= ${PKGBASE}
GITHUB_TAG=     v2.19

MAINTAINER=     ast@NetBSD.org
HOMEPAGE=       https://code.google.com/archive/p/shellinabox/
COMMENT=        Shell In A Box implements a web server for terminal emulation
LICENSE=        gnu-gpl-v2

EXTRACT_USING=  gtar
USE_TOOLS+=     gtar aclocal automake autoconf gm4 gmake autoheader
USE_LANGUAGES=  c
USE_LIBTOOL=    yes
GNU_CONFIGURE=  yes

.include "../../mk/bsd.prefs.mk"
SIB_USER?=              shellinabox
SIB_GROUP?=             shellinabox
PKG_GROUPS=             ${SIB_GROUP}
PKG_USERS=              ${SIB_USER}:${SIB_GROUP}
PKG_GROUPS_VARS=        SIB_USER
PKG_USERS_VARS=         SIB_GROUP

RCD_SCRIPTS+=           shellinaboxd
RCD_SCRIPT_SRC.shellinaboxd = ${WRKSRC}/shellinaboxd.in

SUBST_CLASSES+=         sib
SUBST_STAGE.sib=        pre-configure
SUBST_MESSAGE.sib=      Fixing shellinaboxd user/group defaults
SUBST_FILES.sib+=       ${WRKSRC}/shellinaboxd.in
SUBST_VARS.sib+=        PREFIX SIB_USER SIB_GROUP

INSTALLATION_DIRS=      sbin ${PKGMANDIR}/man1

post-extract:
	${CP} ${FILESDIR}/shellinaboxd.in ${WRKSRC}

pre-configure:
	${RUN} cd ${WRKSRC} && \
		aclocal && \
		libtoolize --copy --automake && \
		autoheader && \
		autoconf && \
		automake --copy --add-missing --foreign

.include "../../mk/bsd.pkg.mk"
