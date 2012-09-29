# $NetBSD: Makefile,v 1.10 2012/09/29 00:50:39 asau Exp $
#

DISTNAME=	gob2-2.0.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gob2/2.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.5z.com/jirka/gob.html
COMMENT=	Preprocessor for making GObjects with inline C

PKG_DESTDIR_SUPPORT=	none

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
