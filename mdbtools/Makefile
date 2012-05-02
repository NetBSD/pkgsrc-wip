# $NetBSD: Makefile,v 1.6 2012/05/02 08:21:29 noud4 Exp $
#

DISTNAME=		mdbtools-0.6pre1
PKGREVISION=		1
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mdbtools/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://mdbtools.sourceforge.net/
COMMENT=		Microsoft Access Database management tools
LICENSE=		gnu-lgpl-v2 AND gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES

USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	libmdb.pc.in libmdbsql.pc.in

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
