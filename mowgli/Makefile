# $NetBSD: Makefile,v 1.2 2007/09/15 03:32:21 netcap Exp $
#

DISTNAME=	libmowgli-0.4.0
CATEGORIES=	devel
MASTER_SITES=	http://distfiles.atheme.org/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://sacredspiral.co.uk/~nenolod/mowgli/
COMMENT=	Development framework for C (like GLib)

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libmowgli.pc.in

.include "../../mk/bsd.pkg.mk"
