# $NetBSD: Makefile,v 1.10 2006/05/19 16:51:35 ykomatsu Exp $
#

DISTNAME=	regexxer-0.4
CATEGORIES=	devel gnome2
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=regexxer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://regexxer.sourceforge.net/
COMMENT=	Interactive tool for performing search and replace operations

USE_DIRS+=		gnome2-1.5
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
