# $NetBSD: Makefile,v 1.1.1.1 2011/03/20 23:43:21 jihbed Exp $
#

DISTNAME=	xmakemol-5.16
CATEGORIES=	biology
MASTER_SITES=	http://savannah.nongnu.org/download/xmakemol/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.nongnu.org/xmakemol/
COMMENT=	Program for visualizing atomic and molecular systems
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake perl

REPLACE_PERL=	xmake_anim.pl

INSTALLATION_DIRS=	share/applications

post-extract:
	     ${CP} ${FILESDIR}/xmakemol.desktop ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/xmakemol.desktop \
		${DESTDIR}${PREFIX}/share/applications/xmakemol.desktop

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/openmotif/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
