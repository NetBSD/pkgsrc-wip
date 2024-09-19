# $NetBSD: Makefile,v 1.2 2015/08/17 12:49:44 leot1990 Exp $

DISTNAME=	rsstail-2.0
CATEGORIES=	www
MASTER_SITES=	http://www.vanheusden.com/rsstail/
EXTRACT_SUFX=	.tgz

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	https://www.vanheusden.com/rsstail/
COMMENT=	RSS feeds reader with a tail(1)-like interface
LICENSE=	gnu-gpl-v2

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing Makefile
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile=	-e 's,/usr/bin,${PREFIX}/bin,g'
SUBST_SED.makefile+=	-e 's,/usr/share/man,${PREFIX}/${PKGMANDIR},g'
SUBST_SED.makefile+=	-e 's,^CFLAGS=,CFLAGS+=,'
SUBST_SED.makefile+=	-e 's,^LDFLAGS=,LDFLAGS+=,'
SUBST_SED.makefile+=	-e '/CFLAGS/ s,-O2,,'
SUBST_SED.makefile+=	-e '/CC/ s,-Wall -W,${CFLAGS:Q},'
SUBST_SED.makefile+=	-e 's/\$$(DEBUG)//'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../converters/libiconv/buildlink3.mk"
.include "../../www/libmrss/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
