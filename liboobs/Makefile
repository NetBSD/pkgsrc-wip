# $NetBSD: Makefile,v 1.1 2015/01/03 07:10:32 obache Exp $
#

DISTNAME=		liboobs-2.32.0
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/liboobs/2.32/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Lightweight GObject based interface to system-tools-backends
LICENSE=		gnu-gpl-v2

.include "options.mk"

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_LIBTOOL=		YES

.include "../../wip/system-tools-backends/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
