# $NetBSD: Makefile,v 1.1.1.1 2011/03/01 21:52:00 ddeus Exp $

DISTNAME=	bzrtools-${VER}
CATEGORIES=	devel scm
MASTER_SITES=	http://launchpad.net/bzrtools/trunk/${VER}/+download/
VER=		2.3.0

MAINTAINER=	jan.m.danielsson@gmail.com
HOMEPAGE=	http://bazaar-vcs.org/BzrTools
COMMENT=	Collection of plugins for Bazaar

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

WRKSRC=		${WRKDIR}/bzrtools

.include "../../devel/bzr/plugin.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
