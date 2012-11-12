# $NetBSD: Makefile,v 1.3 2012/11/12 12:47:21 noud4 Exp $
#

DISTNAME=	yelp-tools-3.1.1
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://ftp.acc.umu.se/pub/GNOME/sources/yelp-tools/3.1/
EXTRACT_SUFX=	.tar.bz2

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
