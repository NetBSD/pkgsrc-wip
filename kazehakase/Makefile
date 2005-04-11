# $NetBSD: Makefile,v 1.2 2005/04/11 21:13:36 tvierling Exp $
#

DISTNAME=		kazehakase-0.1.7
CATEGORIES=		www
MASTER_SITES=		http://kyushu-u.dl.sourceforge.jp/kazehakase/10070/ \
			http://osdn.dl.sourceforge.jp/kazehakase/10070/ \
			http://keihanna.dl.sourceforge.jp/kazehakase/10070/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://kazehakase.sourceforge.jp/
COMMENT=		Web browser with multiple layout engines support

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

# how can I get a .pc file for the firefox* packages?
.include "../../www/mozilla-gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
