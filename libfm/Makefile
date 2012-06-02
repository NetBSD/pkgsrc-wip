# $NetBSD: Makefile,v 1.3 2012/06/02 14:27:54 jeremy-c-reed Exp $
#

DISTNAME=	libfm-0.1.17
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pcmanfm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pcmanfm.sourceforge.net/
COMMENT=	File management library

PKG_DESTDIR_SUPPORT=	user-destdir

# Instead of depending on fam, use glib2 with kqueue
#DEPENDS=		gio-fam>=0:../../sysutils/gio-fam

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-debug	# don't commit this
USE_TOOLS=		intltool pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/menu-cache/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
