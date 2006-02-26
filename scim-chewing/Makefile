# $NetBSD: Makefile,v 1.1.1.1 2006/02/26 14:53:23 rxg Exp $
#

DISTNAME=		scim-chewing-0.2.1
CATEGORIES=		inputmethod
MASTER_SITES=		http://chewing.csie.net/download/scim/

MAINTAINER=		rxg@NetBSD.org
HOMEPAGE=		http://www.scim-im.org/
COMMENT=		SCIM IMEngine module for Chewing input method

BUILD_USES_MSGFMT=	yes

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/libchewing/buildlink3.mk"
.include "../../wip/scim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
