# $NetBSD: Makefile,v 1.3 2009/01/14 13:56:30 obache Exp $
#

DISTNAME=		scim-pinyin-0.5.91
CATEGORIES=		inputmethod
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scim/}

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://www.scim-im.org/
COMMENT=		SCIM IMEngine module for smart pinyin

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		msgfmt pkg-config gmake
GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/scim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
