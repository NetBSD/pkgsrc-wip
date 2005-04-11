# $NetBSD: Makefile,v 1.6 2005/04/11 21:16:15 tvierling Exp $
#

DISTNAME=		xfe-0.70
CATEGORIES=		wip sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xfe/}

MAINTAINER=		ccatrian@eml.cc
HOMEPAGE=		http://xfe.sourceforge.net/
COMMENT=		MS-Explorer like file manager for X

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

# Message catalog files need to be rebuilt to incorporate fuzzy
# entries, allowed by the -f arg in patch-ac.
pre-build:
		cd ${WRKSRC}/po ; \
		${MAKE} update-po

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/fox/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
