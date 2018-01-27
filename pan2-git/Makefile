# $NetBSD$

DISTNAME=		pan2-2
CATEGORIES=		news
MASTER_SITES=		http://github.com/lostcoder/pan2

MAINTAINER=		rhialto@falu.nl
HOMEPAGE=		http://pan.rebelbase.com/
COMMENT=		Newsreader for GTK2
LICENSE=		gnu-gpl-v2

BUILD_DEPENDS+=		gnome-common>=3.6.0nb1:../../devel/gnome-common
BUILD_DEPENDS+=		gettext-tools-[0-9]*:../../devel/gettext-tools

GIT_REPOSITORIES=	gnome
GIT_REPO.gnome=		git://git.gnome.org/pan2
GIT_MODULE.gnome=	pan2
WRKSRC=			${WRKDIR}/pan2

USE_TOOLS+=		autoconf automake gettext-m4 gmake perl pkg-config
USE_LIBTOOL=		yes
USE_LANGUAGES+=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gnutls

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mail/gmime/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"			# optional
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gtkspell/buildlink3.mk"		# optional
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
