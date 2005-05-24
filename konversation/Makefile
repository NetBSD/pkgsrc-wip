# $NetBSD: Makefile,v 1.10 2005/05/24 10:30:29 rillig Exp $
#

DISTNAME=	konversation-0.15
CATEGORIES=	kde net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=konversation/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://konversation.sourceforge.net/
COMMENT=	KDE IRC Client

GNU_CONFIGURE=	YES
USE_PERL5=	YES
USE_X11=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	gmake

USE_PKGLOCALEDIR=	YES
CONFIGURE_ENV+=		kde_htmldir=${PREFIX}/share/doc/kde/HTML
REPLACE_PERL=		src/konversation/konversation-0.14-mainwindow.pl

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
CONFIGURE_ARGS+=	--disable-threading
.endif

CONFIGURE_ARGS+=	--with-extra-includes=${BUILDLINK_PREFIX.jpeg}/include

.include "../../mk/bsd.pkg.mk"
