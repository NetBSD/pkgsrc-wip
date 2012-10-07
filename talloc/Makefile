# $NetBSD: Makefile,v 1.2 2012/10/07 17:17:22 asau Exp $
#

DISTNAME=	talloc-2.0.1
CATEGORIES=	devel
MASTER_SITES=	http://samba.org/ftp/talloc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://talloc.samba.org/
COMMENT=	Hierarchical pool based memory allocator with destructors
#LICENSE=	# TODO: (see mk/license.mk)

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	talloc.pc.in

# include/talloc.h
CONFLICTS+=	samba-[0-9]*

.include "../../mk/bsd.pkg.mk"
