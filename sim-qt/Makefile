# $NetBSD: Makefile,v 1.3 2005/05/24 10:31:26 rillig Exp $
#

DISTNAME=		sim-0.9.3
PKGNAME=		sim-qt-0.9.3
CATEGORIES=		chat x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sim-icq/}

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://sim-icq.sourceforge.net/
COMMENT=		SIM (Simple Instant Messenger)

USE_TOOLS+=	gmake
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
