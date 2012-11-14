# $NetBSD: Makefile,v 1.5 2012/11/14 00:16:11 othyro Exp $
#

DISTNAME=		Kahua-0.3.4
CATEGORIES=		www
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
