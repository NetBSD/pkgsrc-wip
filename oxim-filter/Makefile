# $NetBSD: Makefile,v 1.2 2011/04/13 14:00:26 obache Exp $
#

DISTNAME=	oxim-filters
PKGNAME=	${DISTNAME}-0.1
CATEGORIES=	inputmethod chinese
MASTER_SITES=	ftp://ftp.opendesktop.org.tw/odp/others/OXIM/Source/tarball/
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://opendesktop.org.tw/demopage/oxim/
COMMENT=	Open X Input Method output filters
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	oxim>=1.4:../../wip/oxim

USE_LANGUAGES=		# empty
USE_TOOLS+=		bash:run

NO_BUILD=		yes

INSTALL_MAKE_FLAGS+=	bindir=${PREFIX}/bin libdir=${PREFIX}/lib

REPLACE_BASH+=	${WRKDIR}/oxim-filters/*/*

.include "../../mk/bsd.pkg.mk"
