# $NetBSD: Makefile,v 1.2 2008/03/06 14:54:09 thomasklausner Exp $
#

DISTNAME=	iksemel-1.3
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://iksemel.googlecode.com/files/

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://iksemel.googlecode.com/files/
COMMENT=	XML parser library mainly designed for Jabber applications

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
INFO_FILES=	yes

PKGCONFIG_OVERRIDE+=	iksemel.pc.in

.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
