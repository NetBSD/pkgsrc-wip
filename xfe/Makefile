# $NetBSD: Makefile,v 1.4 2004/09/09 01:29:54 cetrox Exp $
#

DISTNAME=		xfe-0.70
CATEGORIES=		wip sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xfe/}

MAINTAINER=		ccatrian@eml.cc
HOMEPAGE=		http://xfe.sourceforge.net/
COMMENT=		MS-Explorer like file manager for X

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

pre-build:
		cd ${WRKSRC}/po ; \
		${MAKE} update-po

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/fox/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
