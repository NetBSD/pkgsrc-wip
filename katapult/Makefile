# $NetBSD: Makefile,v 1.3 2008/02/03 14:09:47 shindenmorr Exp $
#

DISTNAME=	katapult-0.3.2.1
PKGREVISION=	1
CATEGORIES=	local
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=katapult/}

MAINTAINER=	shinden@linux.pl
HOMEPAGE=	http://katapult.kde.org/
COMMENT=	Allow faster access to applications, bookmarks, and other items

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
