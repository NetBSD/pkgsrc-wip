# $NetBSD: Makefile,v 1.8 2010/06/13 22:47:20 thomasklausner Exp $
#

DISTNAME=		tilp
PKGNAME=		tilp-6.67-beta3
PKGREVISION=		2
CATEGORIES=		math
MASTER_SITES=		http://www.ticalc.org/pub/unix/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://tilp.info/
COMMENT=		Database of TI calculator model information

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-nls --enable-exit-homedir
USE_TOOLS+=		gmake

.include "../../wip/libticables/buildlink3.mk"
.include "../../wip/libtifiles/buildlink3.mk"
.include "../../wip/libticalcs/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
