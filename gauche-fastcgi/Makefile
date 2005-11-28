# $NetBSD: Makefile,v 1.2 2005/11/28 00:27:24 rillig Exp $
#

DISTNAME=		Gauche-fastcgi-0.1
CATEGORIES=		lang
MASTER_SITES=		http://kyushu-u.dl.sourceforge.jp/gauche/8004/

MAINTAINER=		nel@soraneko.com
HOMEPAGE=		http://kyushu-u.dl.sourceforge.jp/gauche/8004/
COMMENT=		Fastcgi bindings for gauche

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

GAUCHE_VERSION!=	gauche-config -V
PLIST_SUBST+=		GAUCHE_VERSION=${GAUCHE_VERSION:Q}

.include "../../lang/gauche/buildlink3.mk"
.include "../../www/fcgi/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
