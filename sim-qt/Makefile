# $NetBSD: Makefile,v 1.1.1.1 2004/12/10 14:26:06 ianzag Exp $
#

DISTNAME=		sim-0.9.3
PKGNAME=		sim-qt-0.9.3
CATEGORIES=		chat x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sim-icq/}

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://sim-icq.sourceforge.net/
COMMENT=		SIM (Simple Instant Messenger)

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

CONFLICTS+=		sim-kde*

# Use only Qt binding
CONFIGURE_ARGS+= --disable-kde

# Install locale files in proper places
USE_PKGLOCALEDIR= YES

# Disable statical libs installation for plugins
SHLIBTOOL_OVERRIDE=	libtool

# Fix: Clear Makefile dependency on config.status
post-configure:
	${TOUCH} ${WRKSRC}/Makefile

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
