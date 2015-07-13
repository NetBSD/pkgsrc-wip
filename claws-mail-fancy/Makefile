# $NetBSD: Makefile,v 1.6 2015/07/13 09:01:43 thomasklausner Exp $

DISTNAME=	fancy-0.9.15
PKGNAME=	claws-mail-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins_obsolete/

MAINTAINER=	dieter.NetBSD@pandora.be
HOMEPAGE=	http://www.claws-mail.org/downloads/plugins/
COMMENT=	Renders HTML e-mail using the WebKit library
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

.include "../../mail/claws-mail/Makefile.vers"
.include "../../mail/claws-mail/buildlink3.mk"
#.include "../../net/libsoup/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
