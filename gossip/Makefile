# $NetBSD: Makefile,v 1.1.1.1 2003/07/08 11:04:52 xtraeme Exp $
#

DISTNAME=	gossip-0.3
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gossip/0.3/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GTK2 Jabber Instant Messaging client

DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_GNU_ICONV=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../wip/loudmouth/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
