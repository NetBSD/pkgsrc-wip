# $NetBSD: Makefile,v 1.1.1.1 2003/06/05 20:32:25 marc Exp $
#

DISTNAME=		umbrello-1.1.1
CATEGORIES=		graphics kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=uml/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		marc@informatik.uni-bremen.de
HOMEPAGE=		http://uml.sourceforge.net/
COMMENT=		Unified Modelling Language diagram programme for KDE

USE_GMAKE=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool
BUILD_USES_MSGFMT=	YES

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdelibs3/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
