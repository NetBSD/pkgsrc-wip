# $NetBSD: Makefile,v 1.10 2012/10/01 21:57:40 asau Exp $

DISTNAME=	klamav-0.37-source
PKGNAME=	${DISTNAME:S/-source//}
PKGREVISION=	5
CATEGORIES=	security kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=klamav/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://klamav.sourceforge.net/
COMMENT=	Clam Anti-Virus Manager For The KDE Desktop


WRKSRC=		${WRKDIR}/${DISTNAME}/${PKGNAME_NOREV}

USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes

# doesn't use embedded sqlite
CONFIGURE_ARGS+=	--without-included-sqlite
.include "../../databases/sqlite3/buildlink3.mk"

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../security/clamav/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
