# $NetBSD: Makefile,v 1.1.1.1 2003/10/13 14:01:53 adrian_p Exp $
#

DISTNAME=	konversation-0.12
PKGREVISION=	2
CATEGORIES=	kde net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=konversation/}

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://konversation.sourceforge.net/
COMMENT=	KDE IRC Client

#USE_X11BASE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV+= ac_cv_path_kde_incdirs=${PREFIX}/include
CONFIGURE_ENV+= ac_cv_path_kde_libdirs=${PREFIX}/lib

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
