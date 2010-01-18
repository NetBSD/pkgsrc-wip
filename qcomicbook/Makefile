# $NetBSD: Makefile,v 1.4 2010/01/18 09:38:30 thomasklausner Exp $
#

DISTNAME=		qcomicbook-0.3.4
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		http://linux.bydg.org/~yogin/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://linux.bydg.org/~yogin/
COMMENT=		Viewer for comic book archives

DEPENDS+=		unace-[0-9]*:../../archivers/unace
DEPENDS+=		unrar-[0-9]*:../../archivers/unrar
DEPENDS+=		unzip-[0-9]*:../../archivers/unzip
BUILD_DEPENDS+=		imlib2-[0-9]*:../../graphics/imlib2
BUILD_DEPENDS+=		qt3-libs>=3.3.3:../../x11/qt3-libs

USE_LANGUAGES=		c c++
USE_TOOLS=		gmake pkg-config
GNU_CONFIGURE=		yes

.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/qt3/application.mk"
.include "../../mk/bsd.pkg.mk"
