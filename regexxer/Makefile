# $NetBSD: Makefile,v 1.1.1.1 2003/06/24 09:35:23 xtraeme Exp $
#

DISTNAME=	regexxer-0.4
CATEGORIES=	devel gnome2
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=regexxer/}

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://regexxer.sourceforge.net/
COMMENT=	Interactive tool for performing search and replace operations

DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11=		yes

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libsigc++/buildlink2.mk"
.include "../../devel/pcre/buildlink2.mk"
.include "../../x11/gtkmm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
