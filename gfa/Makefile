# $NetBSD: Makefile,v 1.4 2012/09/29 00:50:34 asau Exp $
#

DISTNAME=	gfa-0.4.1
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gfa/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gfa.sourceforge.net/
COMMENT=	Gfa a GTK+ fast address

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	share

post-install:
	${INSTALL_DATA} ${WRKSRC}/README  ${DESTDIR}${PREFIX}/share/gfa


.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
