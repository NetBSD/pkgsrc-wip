# $NetBSD: Makefile,v 1.4 2006/05/01 14:20:07 shattered Exp $
#

DISTNAME=		Gauche-fastcgi-0.1
CATEGORIES=		lang
MASTER_SITES=		http://prdownloads.sourceforge.jp/gauche/8004/

MAINTAINER=		nel@soraneko.com
HOMEPAGE=		http://sourceforge.jp/projects/gauche/
COMMENT=		Fastcgi bindings for gauche

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.if exists(${PREFIX}/bin/gauche-config)
GAUCHE_VERSION!=	gauche-config -V
.endif

PLIST_SUBST+=		GAUCHE_VERSION=${GAUCHE_VERSION:Q}

.include "../../lang/gauche/buildlink3.mk"
.include "../../www/fcgi/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
