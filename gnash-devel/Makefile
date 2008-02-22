# $NetBSD: Makefile,v 1.1.1.1 2008/02/22 21:32:53 pmatias Exp $
#

DISTNAME=	gnash-0.8.2rc1
PKGNAME=	gnash-0.8.2rc1  # needed because of cvs-package.mk
CATEGORIES= multimedia
MASTER_SITES=   #

MAINTAINER=	matias@dotbsd.org
HOMEPAGE=	http://www.gnashdev.org/
COMMENT=    GPL Flash movie player

CVS_REPOSITORIES=	gnash
CVS_ROOT.gnash=		${CVS_ROOT_GNU}/gnash
CVS_TAG.gnash=		release_0_8_2_rc1

PKG_DESTDIR_SUPPORT=    user-destdir

USE_PKGLOCALEDIR=       yes
USE_LANGUAGES=          c c++
USE_LIBTOOL=            yes
GNU_CONFIGURE=          yes
USE_TOOLS+=             bash gmake msgfmt pkg-config aclocal \
                        autoheader automake autoconf

WRKSRC=		${WRKDIR}/gnash

CONFIG_SHELL=           ${TOOLS_BASH}

.include "options.mk"

PLIST_SRC+=             ${PKGDIR}/PLIST

pre-configure:
	cd ${WRKSRC}; ./autogen.sh

post-install:
	cp ${WRKSRC}/plugin/.libs/libgnashplugin.so ${PREFIX}/lib/firefox/plugins || ${TRUE}


.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
