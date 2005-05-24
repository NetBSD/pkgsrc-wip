# $NetBSD: Makefile,v 1.4 2005/05/24 10:31:45 rillig Exp $
#

DISTNAME=		tilp
PKGNAME=		tilp-6.67-beta3
CATEGORIES=		math
MASTER_SITES=		http://www.ticalc.org/pub/unix/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://tilp.info/
COMMENT=		Database of TI calculator model information

WRKSRC=			${WRKDIR}/${PKGNAME}

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
.include "../../devel/libglade2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
