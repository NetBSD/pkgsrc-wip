# $NetBSD: Makefile,v 1.5 2003/08/28 09:48:46 xtraeme Exp $
#

DISTNAME=		gtranslator-0.99
CATEGORIES=		devel
MASTER_SITES=		http://www.gtranslator.org/download/releases/0.99/

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.gtranslator.org/
COMMENT=		Gettext po file editor for the GNOME desktop environment

BUILD_USES_MSGFMT=	YES
DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES

MANCOMPRESSED=		gtranslator.1.gz pozilla.sh.1.gz

CONFIGURE_ARGS+=	--disable-debug

.include "../../converters/libiconv/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
