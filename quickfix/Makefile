# $NetBSD: Makefile,v 1.4 2010/03/21 20:40:55 alnsn Exp $

DISTNAME=		quickfix-1.13.2
CATEGORIES=		finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=quickfix/}

OWNER=			alnsn@yandex.ru
HOMEPAGE=		http://www.quickfixengine.org/
COMMENT=		FIX engine
LICENSE=		quickfix

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

WRKSRC=			${WRKDIR}/quickfix

USE_LANGUAGES+=	c c++
PTHREAD_OPTS+=	native
PTHREAD_AUTO_VARS=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=		gmake bash

.include "../../mk/pthread.buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
