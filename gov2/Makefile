# $NetBSD: Makefile,v 1.7 2005/04/11 21:12:33 tvierling Exp $
#

DISTNAME=	gob2-2.0.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gob2/2.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.5z.com/jirka/gob.html
COMMENT=	Preprocessor for making GObjects with inline C

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
