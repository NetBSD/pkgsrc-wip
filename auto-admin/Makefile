# $NetBSD: Makefile,v 1.4 2015/01/25 19:59:53 outpaddling Exp $
#

DISTNAME=	auto-admin-0.3.4
CATEGORIES=	pkgtools
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://acadix.biz/Ports/distfiles/
COMMENT=	Automate common systems administration tasks
#LICENSE=	original-bsd
EXTRACT_SUFX=	.tar.xz

USE_LANGUAGES=	# none

NO_BUILD=	yes

.include "../../mk/bsd.prefs.mk"

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/Common/Scripts/* \
		${DESTDIR}${PREFIX}/sbin
# Why doesn't this work?
#.if exists(${WRKSRC}/Scripts/${OPSYS})
.if ${OPSYS} == NetBSD
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/${OPSYS}/* \
		${DESTDIR}${PREFIX}/sbin
.endif
.if exists(/etc/redhat-release)
	${INSTALL_SCRIPT} ${WRKSRC}/CentOS/Scripts/* \
		${DESTDIR}${PREFIX}/sbin
.endif

.include "../../mk/bsd.pkg.mk"
