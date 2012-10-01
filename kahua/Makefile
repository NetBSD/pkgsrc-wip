# $NetBSD: Makefile,v 1.4 2012/10/01 21:57:33 asau Exp $
#

DISTNAME=		Kahua-0.3.4
CATEGORIES=		wip
MASTER_SITES=		http://www.kahua.org/download/kahua/
EXTRACT_SUFX=		.tgz

MAINTAINER=		nel@soraneko.com
HOMEPAGE=		http://www.kahua.org/download/kahua/
COMMENT=		Kahua is a web application framework for Gauche

PKG_DESTDIR_SUPPORT=	none

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../lang/gauche/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
