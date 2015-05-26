# $NetBSD: Makefile,v 1.1 2015/05/26 11:10:46 f8l Exp $

DISTNAME=	dwb-2014.03.07
CATEGORIES=	www
MASTER_SITES=	https://bitbucket.org/portix/dwb/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://portix.bitbucket.org/dwb/
COMMENT=	Dynamic WebKit browser, gtk3 version
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake
USE_TOOLS+=	pkg-config
NO_CONFIGURE=	yes
MAKE_ENV+=	REAL_VERSION=2014.03.07
MAKE_ENV+=	MANDIR=$(PREFIX)/man
MAKE_ENV+=	GTK=3

.include "../../wip/webkit-gtk3/buildlink3.mk"
#.include "../../x11/gtk3/buildlink3.mk"
#.include "../../net/libsoup24/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
