# $NetBSD: Makefile,v 1.3 2003/12/29 22:05:27 adrian_p Exp $
#

DISTNAME=	konversation-0.13
CATEGORIES=	kde net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=konversation/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://konversation.sourceforge.net/
COMMENT=	KDE IRC Client

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_PERL5=	YES
#USE_X11BASE=    YES

post-configure:
	cd ${WRKSRC}/konversation && \
	${QTDIR}/bin/uic -o prefspageirccolorsui.h prefspageirccolorsui.ui && \
	${QTDIR}/bin/uic -o irccolorchooserui.h irccolorchooserui.ui

.include "../../x11/kdebase3/buildlink2.mk"
.include "../../x11/qt3-tools/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
