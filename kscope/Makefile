# $NetBSD: Makefile,v 1.4 2004/12/28 15:37:32 martijnb Exp $
#

DISTNAME=		kscope-1.0
CATEGORIES=		devel kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kscope/}
PKGREVISION=		1
MAINTAINER=		martijn.van.buul@gmail.com
HOMEPAGE=		http://kscope.sourceforge.net/
COMMENT=		KDE frontend for cscope

DEPENDS+=		cscope>=15.4nb4:../../devel/cscope
DEPENDS+=		exctags>=5.5.4:../../devel/exctags

WRKSRC=			${WRKDIR}/kscope-1.0
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

post-build:
	@${SED} -e "s,@LOCALBASE@,${LOCALBASE},g" \
		${FILESDIR}/kscoperc > ${WRKDIR}/kscoperc

pre-install:
	${INSTALL_DATA_DIR} ${KDEDIR}/share/kde/config
	${INSTALL_DATA} ${WRKDIR}/kscoperc ${KDEDIR}/share/kde/config

.include "../../meta-pkgs/kde3/kde3.mk"

.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

