# $NetBSD$
#

DISTNAME=	auto-admin-0.4.0
CATEGORIES=	pkgtools
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
HOMEPAGE=	http://acadix.biz/Ports/distfiles/
COMMENT=	Automate common systems administration tasks
LICENSE=	2-clause-bsd
EXTRACT_SUFX=	.tar.xz

USE_LANGUAGES=	# none

NO_BUILD=	yes
REPLACE_SH=	*/Scripts/*

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	${WRKSRC}/Common/Scripts/auto-denyhosts-remove-ip
SUBST_SED.prefix=	-e "s|/usr/local|${PREFIX}|g"

INSTALLATION_DIRS=	sbin

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Common/Scripts/* \
		${DESTDIR}${PREFIX}/sbin
	ls ${WRKSRC}/${OPSYS}/Scripts
# This does not work
#.if exists(${WRKSRC}/${OPSYS}/Scripts)
# This does not work
#.if exists(/usr/pkgsrc/wip/auto-admin/work/auto-admin-0.4.0)
# This does work
# .if exists(/usr/pkgsrc/wip/auto-admin/work)
# Temporary hack
.if ${OPSYS} == NetBSD
	@${ECHO} "Installing ${WRKSRC}/${OPSYS}/Scripts/*"
	${INSTALL_SCRIPT} ${WRKSRC}/${OPSYS}/Scripts/* \
		${DESTDIR}${PREFIX}/sbin
.endif
.if exists(/etc/redhat-release)
	${INSTALL_SCRIPT} ${WRKSRC}/CentOS/Scripts/* \
		${DESTDIR}${PREFIX}/sbin
.endif

.include "../../mk/bsd.pkg.mk"
