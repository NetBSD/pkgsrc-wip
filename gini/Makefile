# $NetBSD: Makefile,v 1.1.1.1 2003/04/27 04:25:19 xtraeme Exp $
#

DISTNAME=		gini-0.5.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gini/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jrp@hispabsd.org
HOMEPAGE=		http://gini.sourceforge.net/
COMMENT=		Free streaming media server

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../devel/glib/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
