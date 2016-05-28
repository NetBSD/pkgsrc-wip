# $NetBSD: Makefile,v 1.4 2012/10/03 15:09:59 asau Exp $
#

DISTNAME=		mtrack-0.3
CATEGORIES=		ham x11
MASTER_SITES=		http://www.qsl.net/g4klx/

MAINTAINER=		dawszy@arhea.pl
HOMEPAGE=		http://www.qsl.net/g4klx/
COMMENT=		Satellite tracking program for amateurs


NO_CONFIGURE=		yes

pre-build:
	${SED} -e 's:@PREFIX@:${PREFIX}:' \
		${WRKSRC}/Makefile \
		> ${WRKSRC}/Makefile.new
	${MV} ${WRKSRC}/Makefile.new ${WRKSRC}/Makefile

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
