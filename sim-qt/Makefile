# $NetBSD: Makefile,v 1.11 2012/10/07 16:23:06 asau Exp $
#

DISTNAME=		sim-0.9.3
PKGNAME=		sim-qt-0.9.3
PKGREVISION=		4
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

CONFIGURE_ARGS+=	--with-openssl-inc=${SSLBASE}/include
CONFIGURE_ARGS+=	--with-openssl-lib=${SSLBASE}/lib

# Install locale files in proper places
USE_PKGLOCALEDIR= YES

# Disable statical libs installation for plugins
SHLIBTOOL_OVERRIDE=	libtool

# Fix: Clear Makefile dependency on config.status
post-configure:
	${TOUCH} ${WRKSRC}/Makefile

.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt3-tools+=	qt3-tools>=3.3.5nb6
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
