# $NetBSD: Makefile,v 1.12 2006/01/05 10:11:25 ghen Exp $
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
USE_LIBTOOL=	YES
USE_TOOLS+=	gmake

USE_PKGLOCALEDIR=	YES
CONFIGURE_ENV+=		kde_htmldir=${PREFIX}/share/doc/kde/HTML
REPLACE_PERL=		src/konversation/konversation-0.14-mainwindow.pl

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
# XXX Please verify whether qt3-tools is really needed at run-time.
# If it is, then remove this comment.  If it is not, then remove
# this comment and the line below, and bump PKGREVISION.
BUILDLINK_DEPMETHOD.qt3-tools=	full
.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
CONFIGURE_ARGS+=	--disable-threading
.endif

CONFIGURE_ARGS+=	--with-extra-includes=${BUILDLINK_PREFIX.jpeg}/include

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
