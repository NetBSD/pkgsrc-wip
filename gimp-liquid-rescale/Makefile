# $NetBSD: Makefile,v 1.2 2007/10/24 08:32:39 tnn2 Exp $
#

DISTNAME=		gimp-lqr-plugin-0.3.0-3
PKGNAME=		gimp-liquid-rescale-0.3.0
CATEGORIES=		graphics
MASTER_SITES=		http://liquidrescale.wikidot.com/local--files/en:download-page/

MAINTAINER=		tnn@NetBSD.org
HOMEPAGE=		http://liquidrescale.wikidot.com/
COMMENT=		Content-aware image resizing plugin for the GIMP

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		intltool msgfmt pkg-config gmake
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/gimp-lqr-plugin-0.3.0
PTHREAD_AUTO_VARS=	yes

.include "../../graphics/gimp/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
