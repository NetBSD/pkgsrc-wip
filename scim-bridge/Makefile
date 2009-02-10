# $NetBSD: Makefile,v 1.1.1.1 2009/02/10 12:20:49 obache Exp $
#

DISTNAME=	scim-bridge-0.4.15.2
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scim/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.scim-im.org/projects/scim_bridge
COMMENT=	C wrapper library for SCIM

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/scim-bridge-0.4.15
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--enable-agent
CONFIGURE_ARGS+=	--disable-documents
CONFIGURE_ARGS+=	--disable-tests

.include "options.mk"

CHECK_PORTABILITY_SKIP=	tests/*

.include "../../wip/scim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
