# $NetBSD: Makefile,v 1.4 2014/10/08 04:20:15 makoto Exp $

DISTNAME=	magit-1.2.0.50
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/magit/
COMMENT=	Emacs client for scm Git
LICENSE=	gnu-gpl-v3

GIT_REPOSITORIES=	master
GIT_REPO.master=	https://github.com/magit/magit.git
GIT_MODULE.master=	magit
# for "SSL certificate problem: unable to get local issuer certificate"
GIT_ENV.master+=	GIT_SSL_NO_VERIFY=true

WRKSRC=		${WRKDIR}/${PKGBASE}
NO_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	gmake makeinfo

.include "../../editors/emacs/modules.mk"

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	Makefile
SUBST_MESSAGE.prefix=	Converting /usr/local to ${PREFIX}, share/info to info, not install 50magit.el
SUBST_STAGE.prefix=	post-patch
SUBST_SED.prefix=	-e 's,/usr/local,${PREFIX},'
SUBST_SED.prefix+=	-e 's,share/info,info,'
SUBST_SED.prefix+=	-e '/50magit/s,^	install,\#	install,'

SUBST_CLASSES+=			buildlink
SUBST_MESSAGE.buildlink=	Add site-lisp in buildlink dir for byte-compile
SUBST_FILES.buildlink=		Makefile
SUBST_STAGE.buildlink=		post-patch
SUBST_SED.buildlink=		-e 's,@@BUILDLINK_DIR@@,${BUILDLINK_DIR},'

INFO_FILES=	yes
BUILD_TARGET=	all
TEST_TARGET=	check

post-patch:
	(cd ${WRKSRC}; ${GMAKE} VERSION=${PKGVERSION} magit-version.el)

.include "../../wip/mk/git-package.mk"
.include "../../wip/git-modes-git/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
