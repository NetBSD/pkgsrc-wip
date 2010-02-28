# $NetBSD: Makefile,v 1.1.1.1 2010/02/28 15:27:17 rhialto Exp $

DISTNAME=		pan2-git-2
CATEGORIES=		news
MASTER_SITES=		http://github.com/lostcoder/pan2

MAINTAINER=		rhialto@falu.nl
HOMEPAGE=		http://pan.rebelbase.com/
COMMENT=		Newsreader for GTK2

# This is the bug-fixing version of Pan maintained by K. Haley.
# It is discussed in the mailing list at
# http://lists.gnu.org/archive/html/pan-users/ .
GIT_REPOSITORIES=	khaley
GIT_REPO.khaley=	git://github.com/lostcoder/pan2.git
WRKSRC=			${WRKDIR}/pan2
CONFIGURE_SCRIPT=	autogen.sh
GNU_CONFIGURE=		YES

USE_TOOLS+=		msgfmt perl pkg-config
USE_TOOLS+=		gmake
USE_TOOLS+=		automake gettext-m4
AUTOMAKE_OVERRIDE=	no	# autogen.sh calls automake-1.9 by version
USE_TOOLS+=		autoconf intltool
USE_LIBTOOL=		YES
USE_LANGUAGES+=		c c++
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
#CONFIGURE_ARGS=		--enable-debug
#CONFIGURE_ENV+=		CXXFLAGS=-ggdb
#CONFIGURE_ENV+=		CFLAGS=-ggdb
#CONFIGURE_ENV+=		LDFLAGS=-ggdb

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"
.if (${OPSYS} != "Darwin" && ${OPSYS} != "SunOS" && ${OPSYS} != "Linux")
LIBS+=			-lcompat
.endif

BUILD_DEPENDS+=		gnome-common>=2.28:../../devel/gnome-common

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mail/gmime24/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
