# $NetBSD: Makefile,v 1.9 2004/07/27 22:17:10 thomasklausner Exp $
#

DISTNAME=		fwbuilder-1.0.11
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fwbuilder/}

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://www.fwbuilder.org/
COMMENT=		Firewall configuration and management tool

USE_X11=		yes
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
BUILD_USES_MSGFMT=	yes
BUILD_USES_GETTEXT_M4=	yes
USE_GCC_SHLIB=		yes
GCC_REQD=		2.95.3

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/libtoolize --force --copy
	cd ${WRKSRC} && ${ACLOCAL}
	cd ${WRKSRC} && ${AUTOCONF}

.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../security/libfwbuilder/buildlink3.mk"
.include "../../x11/gtk--/buildlink3.mk"

.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
