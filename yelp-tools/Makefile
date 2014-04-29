# $NetBSD: Makefile,v 1.5 2014/04/29 16:02:06 thomasklausner Exp $

DISTNAME=	yelp-tools-3.12.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/yelp-tools/3.12/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Set of command-line tools to build and check your documentation
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/yelp-xsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
