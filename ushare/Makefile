# $NetBSD: Makefile,v 1.2 2007/08/19 02:15:59 obache Exp $
#

DISTNAME=	ushare-1.0
CATEGORIES=	net multimedia
MASTER_SITES=	http://ushare.geexbox.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://ushare.geexbox.org/
COMMENT=	UPnP AV Mediaserver

USE_LANGUAGES=	c c++
USE_PKGINSTALL=	yes
USE_TOOLS+=	gmake pkg-config

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv:Q}
CONFIGURE_ARGS+=	--with-libupnp=${BUILDLINK_PREFIX.libupnp:Q}

BROKEN_GETTEXT_DETECTION=	yes

CONF_FILES=	${PREFIX}/share/examples/ushare.conf ${PKG_SYSCONFDIR:Q}/ushare.conf
RCD_SCRIPTS=	ushare

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../net/libupnp/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
