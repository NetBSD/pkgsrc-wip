# $NetBSD: Makefile,v 1.4 2004/01/25 02:23:29 grantbeattie Exp $
#

DISTNAME=	kgpg-1.1
WRKSRC=		${WRKDIR}/kgpg
CATEGORIES=	security
MASTER_SITES=	http://devel-home.kde.org/~kgpg/src/

MAINTAINER=	ingolf@users.sourceforge.net
HOMEPAGE=	http://devel-home.kde.org/~kgpg/
COMMENT=	Simple, free, open source KDE frontend for gpg

DEPENDS+=	gnupg>=1.2:../../security/gnupg

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_TOOLS+=		make

.include "../../mk/bsd.prefs.mk"

.include "../../x11/qt3-libs/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdelibs3/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
