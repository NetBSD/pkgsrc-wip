# $NetBSD: Makefile,v 1.1.1.1 2004/02/02 02:14:42 dawszy Exp $
#

DISTNAME=		mtrack-0.3
CATEGORIES=		ham x11
MASTER_SITES=		http://www.qsl.net/g4klx/

MAINTAINER=		dawszy@arhea.pl
HOMEPAGE=		http://www.qsl.net/g4klx/
COMMENT=		Satellite tracking program for amateurs

USE_BUILDLINK2=		yes
NO_CONFIGURE=		yes

pre-build:
	${SED} -e 's:@PREFIX@:${PREFIX}:' \
		${WRKSRC}/Makefile \
		> ${WRKSRC}/Makefile.new
	${MV} ${WRKSRC}/Makefile.new ${WRKSRC}/Makefile

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
