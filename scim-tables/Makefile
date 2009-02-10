# $NetBSD: Makefile,v 1.4 2009/02/10 12:30:43 obache Exp $
#

DISTNAME=		scim-tables-0.5.9
CATEGORIES=		inputmethod
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scim/}

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://www.scim-im.org/
COMMENT=		Data files for SCIM Generic Table Input Method module

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES+=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		msgfmt pkg-config
GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/scim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
