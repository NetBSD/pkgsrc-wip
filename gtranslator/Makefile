# $NetBSD: Makefile,v 1.2 2003/04/14 03:50:09 xtraeme Exp $
#

DISTNAME=	gtranslator-0.43
CATEGORIES=	devel
MASTER_SITES=	http://www.gtranslator.org/download/releases/0.43/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.gtranslator.org/
COMMENT=	Gettext po file editor for the GNOME desktop environment

BUILD_USES_MSGFMT=	YES
DEPENDS+=		gnome-dirs>=1.1:../../misc/gnome1-dirs

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES

CONFIGURE_ARGS+=	--enable-debug=no	\
			--enable-mime-bind=yes	\
			--sysconfdir=${PKG_SYSCONFDIR}

MANCOMPRESSED=		gtranslator.1.gz pozilla.sh.1.gz

.include "../../mk/pthread.buildlink2.mk"
.include "../../devel/gal/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../sysutils/gnome-vfs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
