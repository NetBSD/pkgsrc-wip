# $NetBSD: Makefile,v 1.2 2008/01/18 04:30:13 tnn2 Exp $
#

DISTNAME=		gnash-0.8.1
PKGREVISION=		1
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_GNU:=gnash/0.8.1/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnashdev.org/
#HOMEPAGE=		http://www.gnu.org/software/gnash/
COMMENT=		GPL Flash movie player

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		bash gmake msgfmt pkg-config

# /bin/sh finds a syntax error without line number
CONFIG_SHELL=		${TOOLS_BASH}

.include "options.mk"

PLIST_SRC+=		${PKGDIR}/PLIST

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
