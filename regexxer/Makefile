# $NetBSD: Makefile,v 1.4 2004/04/15 11:03:08 jmmv Exp $
#

DISTNAME=	regexxer-0.4
CATEGORIES=	devel gnome2
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=regexxer/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://regexxer.sourceforge.net/
COMMENT=	Interactive tool for performing search and replace operations

USE_BUILDLINK2=		yes
USE_DIRS+=		gnome2-1.5
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libsigc++/buildlink2.mk"
.include "../../devel/pcre/buildlink2.mk"
.include "../../x11/gtkmm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
