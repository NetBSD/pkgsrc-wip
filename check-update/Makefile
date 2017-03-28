# $NetBSD$

DISTNAME=	check-update-0.9.2
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_GITHUB:=makoto-fujiwara/}

MAINTAINER=	mef@NetBSD.org
HOMEPAGE=	https://github.com/makoto-fujiwara/check-update
COMMENT=	Check pkgsrc trees for newer version
LICENSE=	modified-bsd

DEPENDS+=       httping-[0-9]*:../../net/httping
DEPENDS+=	p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS
DEPENDS+=	curl-[0-9]*:../../www/curl
DEPENDS+=       p5-Algorithm-Diff-[0-9]*:../../devel/p5-Algorithm-Diff
DEPENDS+=	ruby[0-9]*-base-[0-9]*:../../lang/${RUBY_PKGPREFIX}-base
DEPENDS+=	p5-Algorithm-Diff-[0-9]*:../../devel/p5-Algorithm-Diff
DEPENDS+=	p5-Mozilla-CA-[0-9]*:../../security/p5-Mozilla-CA

USE_TOOLS+=	perl:run
NO_BUILD=       YES

CHECK_UPDATE_DIR= share/check-update
MAKEDIR=	${VARBASE}/check-update
EGDIR=		share/examples/check-update

CONF_FILES+=	${EGDIR}/Makefile	   ${MAKEDIR}/Makefile
CONF_FILES+=	${EGDIR}/environment-sample.mk	${MAKEDIR}/environment.mk
CONF_FILES+=	${EGDIR}/check-update-sample.sh   ${MAKEDIR}/check-update.sh
CONF_FILES+=	${EGDIR}/cd-and-sh-sample ${MAKEDIR}/cd-and-sh

OWN_DIRS+=	${MAKEDIR}

MAKE_FILES=	Makefile environment-sample.mk
MAKE_SCRIPTS=	cd-and-sh-sample check-update-sample.sh

INSTALLATION_SCRIPT+=	summary-diff collect-stats fork-w3m merge-check-update
INSTALLATION_FILE=	MaturedList
INSTALLATION_DIRS+=	sbin share/check-update ${EGDIR}

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_MESSAGE.path=	Adjusting executable path
SUBST_FILES.path=	check-update
#SUBST_SED.path=	-e 's,@@CHECK_UPDATE_DIR@@,${PREFIX}/${CHECK_UPDATE_DIR},'
SUBST_VARS.path=	CHECK_UPDATE_DIR PREFIX

REPLACE_PERL+=	${INSTALLATION_SCRIPT}

do-install:

	(cd ${WRKSRC};  ${INSTALL_SCRIPT} check-update ${DESTDIR}${PREFIX}/sbin )
.for i in ${INSTALLATION_SCRIPT} ${INSTALLATION_FILE}
	(cd ${WRKSRC};	${INSTALL_SCRIPT} ${i} ${DESTDIR}${PREFIX}/${CHECK_UPDATE_DIR} )
.endfor

.for i in ${MAKE_FILES}
	(cd ${WRKSRC};	${INSTALL_DATA}   ${i} ${DESTDIR}${PREFIX}/${EGDIR})
.endfor

.for i in ${MAKE_SCRIPTS}
	(cd ${WRKSRC};	${INSTALL_SCRIPT} ${i} ${DESTDIR}${PREFIX}/${EGDIR})
.endfor
.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
