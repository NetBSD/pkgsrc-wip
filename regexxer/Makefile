# $NetBSD: Makefile,v 1.6 2004/05/07 01:58:13 xtraeme Exp $
#

DISTNAME=	regexxer-0.4
CATEGORIES=	devel gnome2
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=regexxer/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://regexxer.sourceforge.net/
COMMENT=	Interactive tool for performing search and replace operations

USE_BUILDLINK3=		yes
USE_DIRS+=		gnome2-1.5
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
