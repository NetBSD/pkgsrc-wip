# $NetBSD: Makefile,v 1.9 2015/07/13 21:32:57 leot1990 Exp $

DISTNAME=	sic-1.2
CATEGORIES=	chat
MASTER_SITES=	http://dl.suckless.org/tools/

MAINTAINER=	smoppy@gmail.com
HOMEPAGE=	http://tools.suckless.org/sic
COMMENT=	Simple IRC client
LICENSE=	mit

MAKE_JOBS_SAFE=	no

SUBST_CLASSES+=		configmk
SUBST_STAGE.configmk=	pre-configure
SUBST_MESSAGE.configmk=	Fixing config.mk
SUBST_FILES.configmk=	config.mk
SUBST_SED.configmk+=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.configmk+=	-e 's,share/man,${PKGMANDIR},g'
SUBST_SED.configmk+=	-e 's/cc/${CC:Q}/'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
