# $NetBSD: Makefile,v 1.2 2012/05/21 16:18:49 jeremy-c-reed Exp $
#

DISTNAME=	libfm-0.1.17
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pcmanfm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pcmanfm.sourceforge.net/
COMMENT=	File management library

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS=		gio-fam>=0:../../sysutils/gio-fam

GNU_CONFIGURE=		yes
USE_TOOLS=		intltool pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/menu-cache/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
