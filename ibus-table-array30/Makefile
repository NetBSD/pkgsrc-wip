# $NetBSD: Makefile,v 1.1.1.1 2010/01/13 10:58:55 obache Exp $
#

DISTNAME=	ibus-table-array30-1.2.0.20090729-Source
PKGNAME=	${DISTNAME:S/-Source//}
CATEGORIES=	inputmethod chinese
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	Array30 Chinese input method for ibus
LICENSE=	gnu-gpl-v2

DEPENDS+=	ibus-table>=1.2.0:../../wip/ibus-table

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=		yes
USE_LANGUAGES=		c c++

.include "../../mk/bsd.pkg.mk"
