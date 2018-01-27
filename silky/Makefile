# $NetBSD: Makefile,v 1.12 2014/10/09 14:06:30 thomasklausner Exp $
#

DISTNAME=	silky-0.5.2
PKGREVISION=	2
CATEGORIES=	chat security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=silky/}

MAINTAINER=	oherrala@ee.oulu.fi
HOMEPAGE=	http://silky.sourceforge.net/
COMMENT=	Silky is an easy-to-use graphical SILC client


USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/silky
CONFIGURE_ARGS+=	--with-included-gettext

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/silc-toolkit/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
