# $NetBSD: Makefile,v 1.6 2015/05/08 14:23:18 outpaddling Exp $
#

DISTNAME=	auto-admin-0.3.5
CATEGORIES=	pkgtools
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
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
	${INSTALL_SCRIPT} ${WRKSRC}/${OPSYS}/Scripts/* \
		${DESTDIR}${PREFIX}/sbin
.endif
.if exists(/etc/redhat-release)
	${INSTALL_SCRIPT} ${WRKSRC}/CentOS/Scripts/* \
		${DESTDIR}${PREFIX}/sbin
.endif

.include "../../mk/bsd.pkg.mk"
