# $NetBSD: Makefile,v 1.3 2006/06/23 01:22:36 obache Exp $

DISTNAME=		gmediaserver-0.11.0
CATEGORIES=		multimedia net
MASTER_SITES=		http://download.savannah.gnu.org/releases/gmediaserver/

MAINTAINER=		obata@lins.jp
HOMEPAGE=		http://www.gnu.org/software/gmediaserver/
COMMENT=		UPnP compatible media server for the GNU system

USE_TOOLS+=		perl pkg-config gmake makeinfo msgfmt
GNU_CONFIGURE=		yes
INFO_FILES=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--with-id3lib=${BUILDLINK_PREFIX.id3lib:Q}
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv:Q}
CONFIGURE_ARGS+=	--with-libupnp=${BUILDLINK_PREFIX.libupnp:Q}

.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/libupnp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
