# $NetBSD$

DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}${DISTNAME:S/v/-/1}
GITHUB_TAG=	v1.11
GITHUB_PROJECT=	redshift
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jonls/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jonls.dk/redshift/
COMMENT=	Redshift adjusts the color temperature of your screen
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autopoint autoreconf intltoolize aclocal autoheader autoconf automake gmake intltool msgfmt pkg-config gettext
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--disable-gui

pre-configure:
	set -e; cd ${WRKSRC}; \
	autopoint --force;  autoreconf --force --install --verbose ; intltoolize --force --automake --copy

.include "options.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
