# $NetBSD: Makefile,v 1.1.1.1 2009/03/10 23:58:40 jihbed Exp $
#

DISTNAME=	gfa-0.4.1
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gfa/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://gfa.sourceforge.net/
COMMENT=	Gfa a GTK+ fast address

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	share

post-install:
	${INSTALL_DATA} ${WRKSRC}/README  ${DESTDIR}${PREFIX}/share/gfa


.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
