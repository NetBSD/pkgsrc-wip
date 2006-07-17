# $NetBSD: Makefile,v 1.1.1.1 2006/07/17 21:38:36 thomasklausner Exp $
#

DISTNAME=		qcomicbook-0.2.8
CATEGORIES=		graphics
MASTER_SITES=		http://linux.bydg.org/~yogin/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://linux.bydg.org/~yogin/
COMMENT=		Viewer for comic book archives

DEPENDS+=		zip-[0-9]*:../../archivers/zip
DEPENDS+=		unrar-[0-9]*:../../archivers/unrar

USE_LANGUAGES=		c++
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
