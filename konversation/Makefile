# $NetBSD: Makefile,v 1.5 2005/01/12 17:05:43 adrian_p Exp $
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
USE_X11BASE=	YES
USE_LIBTOOL=	YES

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"

post-configure:
	cd ${WRKSRC}/konversation && \
	${QTDIR}/bin/uic -o prefspageirccolorsui.h prefspageirccolorsui.ui && \
	${QTDIR}/bin/uic -o irccolorchooserui.h irccolorchooserui.ui

.include "../../mk/bsd.pkg.mk"
