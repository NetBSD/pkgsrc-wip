# $NetBSD: Makefile,v 1.6 2005/04/11 21:15:34 tvierling Exp $
#

DISTNAME=	silky-0.5.2
CATEGORIES=	chat security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=silky/}

MAINTAINER=	oherrala@ee.oulu.fi
HOMEPAGE=	http://silky.sf.net/
COMMENT=	Silky is an easy-to-use graphical SILC client

PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_GNU_TOOLS+=make
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/silky
CONFIGURE_ARGS+=	--with-included-gettext

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/silc-toolkit/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
