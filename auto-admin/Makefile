# $NetBSD: Makefile,v 1.2 2014/04/29 20:12:31 outpaddling Exp $
#

DISTNAME=	auto-admin-0.3.3
CATEGORIES=	pkgtools
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://acadix.biz/Ports/distfiles/
COMMENT=	Automate common systems administration tasks
#LICENSE=	original-bsd

USE_LANGUAGES=	# none

NO_BUILD=	yes

.include "../../mk/bsd.prefs.mk"

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/Common/* \
		${DESTDIR}${PREFIX}/sbin
	echo ${OPSYS}
	ls ${WRKSRC}/Scripts/${OPSYS}
# Why doesn't this work?
#.if exists(${WRKSRC}/Scripts/${OPSYS})
.if ${OPSYS} == NetBSD
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/${OPSYS}/* \
		${DESTDIR}${PREFIX}/sbin
.endif
.if exists(/etc/redhat-release)
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/Redhat/* \
		${DESTDIR}${PREFIX}/sbin
.endif

.include "../../mk/bsd.pkg.mk"
