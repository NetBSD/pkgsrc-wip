# $NetBSD: Makefile,v 1.1 2004/09/12 10:54:42 martijnb Exp $
#

DISTNAME=		kscope-0.8a
CATEGORIES=		devel kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kscope/}

MAINTAINER=		martijn.van.buul@gmail.com
HOMEPAGE=		http://kscope.sourceforge.net/
COMMENT=		KDE frontend for cscope

DEPENDS+=		cscope>=15.4nb2:../../devel/cscope
DEPENDS+=		exctags>=5.5.4:../../devel/exctags

WRKSRC=		${WRKDIR}/kscope-0.8
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

.include "../../meta-pkgs/kde3/kde3.mk"

.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
