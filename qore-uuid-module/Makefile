# $NetBSD: Makefile,v 1.3 2014/04/03 10:47:50 nros Exp $

DISTNAME=	qore-uuid-module-1.2
PKGREVISION=	2
CATEGORIES=	wip
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=qore/}
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=	nros@users.sourceforge.net
HOMEPAGE=	http://www.qore.org/
COMMENT=	UUID module for Qore
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
PTHREAD_OPTS+=	require

INSTALL_TARGET=	install install-html-local

.include "options.mk"

.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../wip/qore/buildlink3.mk"
.include "../../wip/qore/module.mk"
.include "../../mk/bsd.pkg.mk"
