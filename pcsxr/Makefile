# $NetBSD: Makefile,v 1.2 2012/09/25 20:07:57 thomasklausner Exp $
#

DISTNAME=	pcsxr-1.9.92
CATEGORIES=	emulators
MASTER_SITES=	http://pcsxr.codeplex.com/downloads/get/
EXTRACT_SUFX=	.tar.bz2

# The distfile needs to be manually fetched from:
# http://pcsxr.codeplex.com/downloads/get/140521 and renamed as shown above.
# The links to the distfilse on CodePlex are not DDLs. This is a huge PITA.

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pcsxr.codeplex.com/
COMMENT=	PlayStation Emulator based on PCSX-df 1.9
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	gettext-m4-[0-9]*:../../devel/gettext-m4

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		aclocal autoconf autoheader automake autoreconf gmake
USE_TOOLS+=		msgfmt msgmerge pkg-config xgettext

.include "options.mk"

pre-configure:
			cd ${WRKSRC} && ./autogen.sh

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/videoproto/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
