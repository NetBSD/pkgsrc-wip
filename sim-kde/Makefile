# $NetBSD: Makefile,v 1.9 2012/10/07 16:23:06 asau Exp $
#

DISTNAME=		sim-0.9.3
PKGNAME=		sim-kde-0.9.3
PKGREVISION=		5
CATEGORIES=		chat x11 kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sim-icq/}

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://sim-icq.sourceforge.net/
COMMENT=		SIM (Simple Instant Messenger)


USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

CONFLICTS+=		sim-qt*

# Use KDE binding
CONFIGURE_ARGS+= --enable-kde

# Install locale files in proper places
USE_PKGLOCALEDIR= YES

# Disable statical libs installation for plugins
SHLIBTOOL_OVERRIDE=	libtool

# Fix: Clear Makefile dependency on config.status
post-configure:
	${TOUCH} ${WRKSRC}/Makefile

.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
