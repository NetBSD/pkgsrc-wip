# $NetBSD: Makefile,v 1.3 2013/12/06 11:31:35 noud4 Exp $
#

DISTNAME=	islamic-menus-1.0.2
CATEGORIES=	misc
MASTER_SITES=	http://launchpad.net/islamic-menu/trunk/1.0/+download/
FETCH_USING=	curl

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://launchpad.net/islamic-menu
COMMENT=	Islamic menu categories for applications under GNOME and KDE
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_TOOLS+=	gmake intltool msgfmt
USE_LANGUAGES=	# none

#INSTALL_MAKE_FLAGS=    PREFIX=${DESTDIR}${PREFIX}


.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
