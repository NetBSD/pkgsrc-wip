# $NetBSD: Makefile,v 1.1 2012/12/30 02:45:17 othyro Exp $
#

DISTNAME=	tilp2-1.16
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tilp/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lpg.ticalc.org/prj_tilp/
COMMENT=	Multi-platform linking program for TI graphing calculators
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake intltool msgfmt msgmerge pkg-config xgettext

.include "options.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
BUILD_DEPENDS+=	libtifiles2-[0-9]*:../../wip/libtifiles2
BUILD_DEPENDS+=	libticonv-[0-9]*:../../wip/libticonv
BUILD_DEPENDS+=	glib2-[0-9]*:../../devel/glib2
.include "../../wip/libticalcs2/buildlink3.mk"
.include "../../wip/libticables2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
