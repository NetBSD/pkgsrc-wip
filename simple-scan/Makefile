# $NetBSD: Makefile,v 1.2 2012/10/07 16:23:06 asau Exp $
#

DISTNAME=	simple-scan-3.4.1
CATEGORIES=	graphics
MASTER_SITES=	https://launchpad.net/simple-scan/3.4/3.4.1/+download/

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	https://launchpad.net/simple-scan/
COMMENT=	Simple scanner graphical interface
#LICENSE=	# TODO: (see mk/license.mk)

# Needed for launchpad
FETCH_USING=	curl

GNU_CONFIGURE=	yes
USE_TOOLS=	pkg-config

.include "../../devel/glib2/buildlink3.mk"

.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

#No package 'gudev-1.0' found

.include "../../mk/bsd.pkg.mk"
