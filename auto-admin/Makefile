# $NetBSD$
#

DISTNAME=	auto-admin-0.3.8
CATEGORIES=	pkgtools
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
HOMEPAGE=	http://acadix.biz/Ports/distfiles/
COMMENT=	Automate common systems administration tasks
#LICENSE=	original-bsd
EXTRACT_SUFX=	.tar.xz

USE_LANGUAGES=	# none

NO_BUILD=	yes
REPLACE_SH=	*/Scripts/*

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	${WRKSRC}/Common/Scripts/auto-denyhosts-remove-ip
SUBST_SED.prefix=	-e "s|/usr/local|${PREFIX}|g"

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
