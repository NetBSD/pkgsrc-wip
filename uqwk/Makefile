# $NetBSD: Makefile,v 1.7 2006/11/11 11:31:06 shattered Exp $

DISTNAME=	uqwk-2.21
CATEGORIES=	news
MASTER_SITES=	http://www.xs4all.nl/~js/warez/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.xs4all.nl/~js/warez/
COMMENT=	Tool to collect news and mail packets for offline reading

GNU_CONFIGURE=	YES

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"
.if !empty(LOWER_OPSYS:Mirix5*)
# needs regex.h
. include "../../pkgtools/libnbcompat/buildlink3.mk"
SUBST_CLASSES+=		 regex_h
SUBST_STAGE.regex_h=	post-patch
SUBST_FILES.regex_h=	score.c
SUBST_SED.regex_h=	-e "s,<regex\\.h>,<nbcompat/regex.h>,"
.endif

.include "../../mk/bsd.pkg.mk"
