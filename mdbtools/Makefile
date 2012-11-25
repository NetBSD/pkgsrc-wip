# $NetBSD: Makefile,v 1.9 2012/11/25 23:32:27 othyro Exp $
#

DISTNAME=		mdbtools-0.6pre1
PKGREVISION=		1
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mdbtools/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mdbtools.sourceforge.net/
COMMENT=		Microsoft Access Database management tools
LICENSE=		gnu-lgpl-v2 AND gnu-gpl-v2

USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES
USE_LIBTOOL=		yes

USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	libmdb.pc.in libmdbsql.pc.in

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
