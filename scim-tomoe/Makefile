# $NetBSD: Makefile,v 1.1.1.1 2009/01/14 14:02:21 obache Exp $
#

DISTNAME=		scim-tomoe-0.6.0
CATEGORIES=		inputmethod
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tomoe/}

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://tomoe.sourceforge.jp/
COMMENT=		SCIM IMEngine module for Tomoe

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES+=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake msgfmt pkg-config intltool
GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/tomoe-gtk/buildlink3.mk"
.include "../../wip/scim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
