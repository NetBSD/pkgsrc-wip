# $NetBSD: Makefile,v 1.6 2014/09/28 16:04:17 genolopolis Exp $
#

DISTNAME=		viewglob-0.9
PKGREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=viewglob/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://viewglob.sourceforge.net/
COMMENT=		Utility designed to complement the shell in graphical environments

DEPENDS+=		bash>=2.0:../../shells/bash


USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
