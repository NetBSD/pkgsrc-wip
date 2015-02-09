# $NetBSD: Makefile,v 1.8 2015/02/09 22:24:32 leot1990 Exp $
#

DISTNAME=	netsurf-all-3.2
PKGNAME=	${DISTNAME:S/-all//}
CATEGORIES=	www
MASTER_SITES=	http://download.netsurf-browser.org/netsurf/releases/source-full/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.netsurf-browser.org/
COMMENT=	Web browser for RISC OS and UNIX-like platforms
LICENSE=	gnu-gpl-v2 AND mit

BUILD_DEPENDS+=	lemon>=1.0:../../devel/lemon
BUILD_DEPENDS+=	re2c>=0.12:../../devel/re2c

BUILD_TARGET=	build
USE_TOOLS+=	bison flex gmake perl:build pax pkg-config

INSTALLATION_DIRS+=	share/netsurf bin

# needed for netsurf-1.2 and gtk2-2.20 -- remove on next update!
#BUILDLINK_TRANSFORM+=	rm:-DG_DISABLE_DEPRECATED
#BUILDLINK_TRANSFORM+=	rm:-DGDK_DISABLE_DEPRECATED
#BUILDLINK_TRANSFORM+=	rm:-DGDK_PIXBUF_DISABLE_DEPRECATED
#BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-Werror

#post-extract:
#	find ${WRKSRC}/!NetSurf -type f | xargs chmod a-x

#do-install:
#	cd ${WRKSRC} && pax -rw !NetSurf ${DESTDIR}${PREFIX}/share/netsurf/
#	cd ${WRKSRC} && pax -rw gtk/res ${DESTDIR}${PREFIX}/share/netsurf/
#	${INSTALL_PROGRAM} ${WRKSRC}/nsgtk ${DESTDIR}${PREFIX}/share/netsurf/nsgtk
#	${INSTALL_SCRIPT} ${WRKSRC}/netsurf ${DESTDIR}${PREFIX}/bin/netsurf

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
