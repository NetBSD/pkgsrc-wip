# $NetBSD: Makefile,v 1.1.1.1 2009/05/15 09:00:53 obache Exp $
#

DISTNAME=	scim-thai-0.1.1
CATEGORIES=	inputmethod
MASTER_SITES=	ftp://linux.thai.net/pub/ThaiLinux/software/libthai/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://linux.thai.net/projects/scim-thai
COMMENT=	SCIM IMEngine module for Thai

LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libthai/buildlink3.mk"
.include "../../wip/scim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
