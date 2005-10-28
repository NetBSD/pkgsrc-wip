# $NetBSD: Makefile,v 1.1.1.1 2005/10/28 02:41:32 dhowland Exp $
#

DISTNAME=		xarchiver-0.2
CATEGORIES=		archivers
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xarchiver/}
EXTRACT_SUFX=           .tar.bz2

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://sourceforge.net/projects/xarchiver/
COMMENT=		GTK2 frontend for tar, bzip2, rar, zip, gzip, rpm

WRKSRC=                 ${WRKDIR}/Xarchiver-0.2

GNU_CONFIGURE=          yes
USE_DIRS+=              xdg-1.2
USE_TOOLS+=		pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
