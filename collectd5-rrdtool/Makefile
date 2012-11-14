DISTNAME=       collectd-5.0.1
PKGNAME=	collectd-rrdtool-5.0.1
MASTER_SITES=   http://collectd.org/files/
CATEGORIES=     net

MAINTAINER=     msporleder@gmail.com
HOMEPAGE=       http://collectd.org/
COMMENT=        Statistics collection daemon - rrdtool plugin
LICENSE=        gnu-gpl-v2

GNU_CONFIGURE=          yes
USE_LIBTOOL=            yes
USE_TOOLS+=             pkg-config
USE_LANGUAGES=          c c++

CONFIGURE_ARGS+=        --with-included-ltdl
CONFIGURE_ARGS+=        --disable-all-plugins
CONFIGURE_ARGS+=        --with-perl-bindings=no
CONFIGURE_ARGS+=        --with-libperl=no
CONFIGURE_ARGS+=        --enable-rrdtool
CONFIGURE_ARGS+=        --with-librrd=${LOCALBASE}

BUILD_DIRS=		src
BUILD_TARGET=		rrdtool.la
INSTALL_DIRS=		src
INSTALL_TARGET=		install-pkglibLTLIBRARIES

DEPENDS+=		collectd>=5:../../wip/collectd5

.include "../../databases/rrdtool/buildlink3.mk"

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
