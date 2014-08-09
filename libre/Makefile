# $NetBSD: Makefile,v 1.5 2014/08/09 23:56:59 thomasklausner Exp $

DISTNAME=	re-0.4.9
PKGNAME=	lib${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://www.creytiv.com/pub/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.creytiv.com/re.html
COMMENT=	Portable library for real-time communications with async IO support
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
NO_CONFIGURE=	yes

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	Makefile
SUBST_MESSAGE.prefix=	Fixing PREFIX path.
SUBST_SED.prefix=	-e "s|/usr/local|${PREFIX}|1"
SUBST_SED.prefix+=	-e "s|/usr|${PREFIX}|1"
SUBST_STAGE.prefix=	post-patch

SUBST_CLASSES+=		re
SUBST_FILES.re=		mk/re.mk
SUBST_MESSAGE.re=	Fixing PREFIX path.
SUBST_SED.re=		-e "s|/usr/local|${PREFIX}|g"
SUBST_STAGE.re=		post-patch

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/lib/libre.a

.include "../../mk/bsd.pkg.mk"
