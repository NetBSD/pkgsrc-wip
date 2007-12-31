# $NetBSD: Makefile,v 1.4 2007/12/31 19:12:41 netcap Exp $
#

DISTNAME=	libmowgli-0.6.0
CATEGORIES=	devel
MASTER_SITES=	http://distfiles.atheme.org/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://atheme.org/projects/mowgli.shtml
COMMENT=	Development framework for C (like GLib)

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libmowgli.pc.in

.include "../../mk/bsd.pkg.mk"
