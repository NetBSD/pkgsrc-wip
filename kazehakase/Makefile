# $NetBSD: Makefile,v 1.1.1.1 2004/07/23 05:05:17 jeremy-c-reed Exp $
#

DISTNAME=		kazehakase-0.1.7
CATEGORIES=		www
MASTER_SITES=		http://kyushu-u.dl.sourceforge.jp/kazehakase/10070/ \
			http://osdn.dl.sourceforge.jp/kazehakase/10070/ \
			http://keihanna.dl.sourceforge.jp/kazehakase/10070/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://kazehakase.sourceforge.jp/
COMMENT=		Web browser with multiple layout engines support

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

# how can I get a .pc file for the firefox* packages?
.include "../../www/mozilla-gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
