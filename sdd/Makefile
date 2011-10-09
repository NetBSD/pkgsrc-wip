# $NetBSD: Makefile,v 1.4 2011/10/09 10:30:32 cheusov Exp $
#

DISTNAME=		sdd-1.52
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.berlios.de/pub/sdd/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://directory.fsf.org/project/sdd/
COMMENT=		Replacement for 'dd'

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
MAKEFLAGS+=		INS_BASE=${PREFIX}/

.include "../../mk/bsd.pkg.mk"
