# $NetBSD: Makefile,v 1.2 2003/06/10 21:36:30 marc Exp $
#

DISTNAME=		fwbuilder-1.0.10
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fwbuilder/}

MAINTAINER=		marc@informatik.uni-bremen.de
HOMEPAGE=		http://www.fwbuilder.org/
COMMENT=		firewall configuration and management tool

USE_CXX=		yes
USE_X11=		yes
USE_GMAKE=		yes
USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
BUILD_USES_MSGFMT=	yes
BUILD_USES_GETTEXT_M4=	yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/libtoolize --force --copy
	cd ${WRKSRC} && ${ACLOCAL}
	cd ${WRKSRC} && ${AUTOCONF}

.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../x11/gtk--/buildlink2.mk"
.include "../../wip/libfwbuilder/buildlink2.mk"

.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
