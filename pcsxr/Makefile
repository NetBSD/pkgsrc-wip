# $NetBSD: Makefile,v 1.7 2013/11/12 12:26:33 othyro Exp $

DISTNAME=	pcsxr-1.9.93
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://pcsxr.codeplex.com/downloads/get/722114
EXTRACT_SUFX=	.tar.bz2
FETCH_MESSAGE=	"Please download the file:"
FETCH_MESSAGE+=	"    "${DISTFILES:Q}
FETCH_MESSAGE+=	"manually from "${MASTER_SITES:Q}"."
# The links to the distfilse on CodePlex are not DDLs. This is a huge PITA.

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pcsxr.codeplex.com/
COMMENT=	PlayStation Emulator based on PCSX-df 1.9
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	gettext-m4-[0-9]*:../../devel/gettext-m4

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		aclocal autoconf autoheader automake autoreconf gmake
USE_TOOLS+=		intltool msgfmt msgmerge pkg-config xgettext

WRKSRC=		${WRKDIR}/${PKGBASE}

.include "options.mk"

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_DEPMETHOD.libXcursor=	build
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
