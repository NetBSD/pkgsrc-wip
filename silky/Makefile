# $NetBSD: Makefile,v 1.2 2004/03/10 13:12:26 oherrala Exp $
#

DISTNAME=	silky-0.5.0
CATEGORIES=	chat security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=silky/}

MAINTAINER=	oherrala@ee.oulu.fi
HOMEPAGE=	http://silky.sf.net/
COMMENT=	Silky is an easy-to-use graphical SILC client

PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_GNU_TOOLS+=make
USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

CONFIGURE_ARGS+=	--with-silc-includes=${BUILDLINK_PREFIX.silc-toolkit}/include/silc-toolkit
CONFIGURE_ARGS+=	--with-silc-libs=${BUILDLINK_PREFIX.silc-toolkit}/lib/silc-toolkit
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/silky
CONFIGURE_ARGS+=	--with-included-gettext

.include "../../x11/gtk2/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../wip/silc-toolkit/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
