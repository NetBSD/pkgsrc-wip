# $NetBSD: Makefile,v 1.2 2003/06/13 14:50:11 marc Exp $
#

DISTNAME=		umbrello-1.1.1
CATEGORIES=		graphics kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=uml/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		marc@informatik.uni-bremen.de
HOMEPAGE=		http://uml.sourceforge.net/
COMMENT=		Unified Modelling Language diagram programme for KDE

USE_GMAKE=		YES
USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool
BUILD_USES_MSGFMT=	YES

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdelibs3/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
