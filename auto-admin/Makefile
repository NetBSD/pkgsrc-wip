# $NetBSD$

DISTNAME=	auto-admin-0.4.0
CATEGORIES=	pkgtools
MASTER_SITES=	http://acadix.biz/Ports/distfiles/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	bacon4000@gmail.com
HOMEPAGE=	http://acadix.biz/Ports/distfiles/
COMMENT=	Automate common systems administration tasks
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

NO_BUILD=	yes
REPLACE_SH=	*/Scripts/*

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix+=	${WRKSRC}/Common/Scripts/auto-denyhosts-setup
SUBST_FILES.prefix+=	${WRKSRC}/Common/Scripts/auto-denyhosts-remove-ip
SUBST_FILES.prefix+=	${WRKSRC}/Common/Scripts/auto-pkgsrc-add-license
SUBST_SED.prefix+=	-e "s|/usr/local|${PREFIX}|g"
SUBST_SED.prefix+=	-e "s|/usr/pkg|${PREFIX}|g"

SUBST_CLASSES+=		pkgsrc
SUBST_STAGE.pkgsrc=	post-patch
SUBST_SED.pkgsrc=	-e 's|/usr/pkgsrc|${BUILD_DIR}/../..|g'
SUBST_FILES.pkgsrc+=	${WRKSRC}/Common/Scripts/auto-clean-pkgsrc
SUBST_FILES.pkgsrc+=	${WRKSRC}/Common/Scripts/auto-print-make-variable

INSTALLATION_DIRS=	sbin

REDHAT_RELEASE=		/etc/redhat-release

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Common/Scripts/* \
		${DESTDIR}${PREFIX}/sbin
	if ${TEST} -e ${WRKSRC}/${OPSYS}/Scripts; then \
	    ${INSTALL_SCRIPT} ${WRKSRC}/${OPSYS}/Scripts/* \
		${DESTDIR}${PREFIX}/sbin; \
	fi
	if ${TEST} -e ${REDHAT_RELEASE}; then \
	    ${INSTALL_SCRIPT} ${WRKSRC}/CentOS/Scripts/* \
		${DESTDIR}${PREFIX}/sbin; \
	fi

.include "../../mk/bsd.pkg.mk"
