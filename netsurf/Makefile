# $NetBSD: Makefile,v 1.4 2008/04/12 14:58:31 hoka_adam Exp $
#

DISTNAME=	netsurf-1.2-src
PKGNAME=	${DISTNAME:S/-src$//}
CATEGORIES=	www
MASTER_SITES=	http://www.netsurf-browser.org/downloads/releases/

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://www.netsurf-browser.org/
COMMENT=	Web browser for RISC OS and UNIX-like platforms

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/netsurf

USE_TOOLS+=	gmake perl:build pax pkg-config

BUILD_DEPENDS+=	re2c>=0.12.*:../../devel/re2c
BUILD_DEPENDS+=	lemon>=1.0:../../wip/lemon

INSTALLATION_DIRS+=	share/netsurf bin

do-install:
	cd ${WRKSRC} && pax -rw !NetSurf ${DESTDIR}${PREFIX}/share/netsurf/
	cd ${WRKSRC} && pax -rw gtk/res ${DESTDIR}${PREFIX}/share/netsurf/
	${INSTALL_PROGRAM} ${WRKSRC}/nsgtk ${DESTDIR}${PREFIX}/share/netsurf/nsgtk
	${INSTALL_SCRIPT} ${WRKSRC}/netsurf ${DESTDIR}${PREFIX}/bin/netsurf

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
