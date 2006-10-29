# $NetBSD: Makefile,v 1.3 2006/10/29 11:23:08 shattered Exp $
#

DISTNAME=		fuse-2.5.2
PKGNAME=		fusefs-2.5.2
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fuse/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://fuse.sourceforge.net/
COMMENT=		Filesystem in Userspace

GNU_CONFIGURE=		YES
ONLY_FOR_PLATFORM=	Linux-*-*
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

.include "../../mk/bsd.pkg.mk"
