# $NetBSD: Makefile,v 1.4 2013/01/19 13:21:53 othyro Exp $
#

DISTNAME=	simple-scan-3.4.1
CATEGORIES=	graphics
MASTER_SITES=	https://launchpad.net/simple-scan/3.4/3.4.1/+download/
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/simple-scan/
COMMENT=	Simple scanner graphical interface
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS=	pkg-config

# XXX No package 'gudev-1.0' found

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
