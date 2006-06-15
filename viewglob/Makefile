# $NetBSD: Makefile,v 1.3 2006/06/15 13:31:57 thomasklausner Exp $
#

DISTNAME=		viewglob-0.9
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=viewglob/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://viewglob.sourceforge.net/
COMMENT=		Utility designed to complement the shell in graphical environments

DEPENDS+=		bash>=2.0:../../shells/bash2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
