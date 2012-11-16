# $NetBSD: Makefile,v 1.1 2012/11/16 22:25:07 helgoman Exp $
#


VERSION=			0.22.0
DISTNAME=			cutecom-${VERSION}
CATEGORIES=			comms
MASTER_SITES=		http://cutecom.sourceforge.net/

MAINTAINER=			helgoman@users.sourceforge.net
HOMEPAGE=			http://cutecom.sourceforge.net/
COMMENT=			Graphical serial terminal
LICENSE=			gnu-gpl-v2

DEPENDS+=       	lrzsz>=0.12.20:../../comms/lrzsz

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"

HAS_CONFIGURE=		yes
USE_CMAKE=			yes
USE_LANGUAGES=		c c++

.include "../../mk/bsd.pkg.mk"
