# $NetBSD: Makefile,v 1.3 2012/10/28 21:05:48 rhialto Exp $

DISTNAME=		pan2-git-2
CATEGORIES=		news
MASTER_SITES=		http://github.com/lostcoder/pan2

MAINTAINER=		rhialto@falu.nl
HOMEPAGE=		http://pan.rebelbase.com/
COMMENT=		Newsreader for GTK2

# These are various repositories for Pan, ordered from latest to oldest.
# It is discussed in the mailing list at
# http://lists.gnu.org/archive/html/pan-users/ .
GIT_REPOSITORIES=	gnome
GIT_REPO.gnome= 	git://git.gnome.org/pan2
GIT_MODULE.gnome=	pan2
GIT_REPO.aexoden=	git://github.com/aexoden/pan2.git
GIT_MODULE.aexoden=	pan2
GIT_REPO.khaley=	git://github.com/lostcoder/pan2.git
GIT_MODULE.khaley=	pan2
WRKSRC=			${WRKDIR}/pan2
CONFIGURE_SCRIPT=	autogen.sh
GNU_CONFIGURE=		YES

USE_TOOLS+=		msgfmt perl pkg-config
USE_TOOLS+=		gmake
USE_TOOLS+=		automake gettext-m4
AUTOMAKE_OVERRIDE=	no	# autogen.sh calls automake-1.12 by version
USE_TOOLS+=		autoconf intltool
USE_LIBTOOL=		YES
USE_LANGUAGES+=		c c++
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
#CONFIGURE_ARGS=		--enable-debug
#CONFIGURE_ENV+=		CXXFLAGS=-ggdb
#CONFIGURE_ENV+=		CFLAGS=-ggdb
#CONFIGURE_ENV+=		LDFLAGS=-ggdb

.include "../../mk/bsd.prefs.mk"
.if (${OPSYS} != "Darwin" && ${OPSYS} != "SunOS" && ${OPSYS} != "Linux")
LIBS+=			-lcompat
.endif

BUILD_DEPENDS+=		gnome-common>=3.6:../../devel/gnome-common

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mail/gmime24/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gnutls
.include "../../security/gnutls/buildlink3.mk"			# optional
.include "../../security/libgnome-keyring/buildlink3.mk"	# optional
.include "../../sysutils/dbus/buildlink3.mk"			# optional
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"		# optional
.include "../../textproc/gtkspell/buildlink3.mk"		# optional
.include "../../x11/gtk2/buildlink3.mk"

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
