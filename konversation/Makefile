# $NetBSD: Makefile,v 1.4 2004/04/26 03:08:00 blef Exp $
#

DISTNAME=	konversation-0.13
CATEGORIES=	kde net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=konversation/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://konversation.sourceforge.net/
COMMENT=	KDE IRC Client

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_PERL5=	YES
#USE_X11BASE=    YES

post-configure:
	cd ${WRKSRC}/konversation && \
	${QTDIR}/bin/uic -o prefspageirccolorsui.h prefspageirccolorsui.ui && \
	${QTDIR}/bin/uic -o irccolorchooserui.h irccolorchooserui.ui

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
