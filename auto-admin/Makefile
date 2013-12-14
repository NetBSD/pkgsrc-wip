# $NetBSD: Makefile,v 1.1 2013/12/14 17:02:43 outpaddling Exp $
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
.if exists(${WRKSRC}/Scripts/${OPSYS})
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/${OPSYS}/* \
		${DESTDIR}${PREFIX}/sbin
.endif
.if exists(/etc/redhat-release)
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/Redhat/* \
		${DESTDIR}${PREFIX}/sbin
.endif

.include "../../mk/bsd.pkg.mk"
