# $NetBSD: Makefile,v 1.1.1.1 2003/06/24 05:42:55 xtraeme Exp $
#

DISTNAME=	gob2-2.0.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gob2/2.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.5z.com/jirka/gob.html
COMMENT=	Preprocessor for making GObjects with inline C

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

.include "../../devel/glib2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
