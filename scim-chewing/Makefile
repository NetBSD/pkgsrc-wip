# $NetBSD: Makefile,v 1.4 2009/11/23 11:37:54 obache Exp $
#

DISTNAME=		scim-chewing-0.3.3
CATEGORIES=		inputmethod
MASTER_SITES=		http://chewing.csie.net/download/scim/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://chewing.csie.net/
COMMENT=		SCIM IMEngine module for Chewing input method

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES+=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake msgfmt pkg-config intltool
GNU_CONFIGURE=		yes

USE_SCIM_GTKUTILS=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/libchewing/buildlink3.mk"
.include "../../wip/scim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
