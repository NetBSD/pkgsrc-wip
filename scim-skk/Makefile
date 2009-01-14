# $NetBSD: Makefile,v 1.3 2009/01/14 13:58:38 obache Exp $
#

DISTNAME=		scim-skk-0.5.2
CATEGORIES=		inputmethod
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE_JP:=scim-imengine/18121/}

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://scim-imengine.sourceforge.jp/
COMMENT=		SCIM IMEngine module for skk

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES+=		c++ c
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		msgfmt pkg-config
GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/scim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
