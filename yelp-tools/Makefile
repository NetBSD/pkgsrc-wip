# $NetBSD: Makefile,v 1.2 2012/10/07 20:11:11 asau Exp $
#

DISTNAME=	yelp-tools-3.1.1
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
.include "../../wip/yelp-xsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
