# $NetBSD: Makefile,v 1.3 2006/01/23 23:12:04 adrian_p Exp $
#

DISTNAME=		Gauche-fastcgi-0.1
CATEGORIES=		lang
MASTER_SITES=		http://kyushu-u.dl.sourceforge.jp/gauche/8004/

MAINTAINER=		nel@soraneko.com
HOMEPAGE=		http://kyushu-u.dl.sourceforge.jp/gauche/8004/
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
