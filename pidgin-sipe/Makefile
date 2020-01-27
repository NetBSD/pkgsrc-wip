# $NetBSD: Makefile,v 1.10 2013/07/06 16:56:24 othyro Exp $
#

DISTNAME=	pidgin-sipe-1.20.1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sipe/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	yacht@users.sourceforge.net
HOMEPAGE=	https://sipe.sourceforge.io/
COMMENT=	Pidgin plugin for Microsoft Office Communicator
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool msgfmt msgmerge pkg-config xgettext

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mail/gmime/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../net/libnice/buildlink3.mk"
.include "../../security/heimdal/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../chat/libpurple/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
