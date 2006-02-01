# $NetBSD: Makefile,v 1.1.1.1 2006/02/01 11:28:16 rxg Exp $
#

DISTNAME=		scim-tables-0.5.6
CATEGORIES=		inputmethod
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scim/}

MAINTAINER=		rxg@NetBSD.org
HOMEPAGE=		http://www.scim-im.org/
COMMENT=		Data files for SCIM Generic Table Input Method module

BUILD_USES_MSGFMT=	yes

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/scim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
