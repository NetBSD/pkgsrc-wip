# $NetBSD: Makefile,v 1.19 2013/12/06 12:29:22 noud4 Exp $
#

DISTNAME=	gurlchecker-0.13.1
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://labs.libre-entreprise.org/frs/download.php/857/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://labs.libre-entreprise.org/projects/gurlchecker/
COMMENT=	Gnome2 program to check a page/website for broken links
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool msgfmt msgmerge perl pkg-config xgettext

.include "options.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../net/gnet/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
