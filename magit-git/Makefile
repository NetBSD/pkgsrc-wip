# $NetBSD: Makefile,v 1.1 2013/06/21 01:20:26 makoto Exp $

DISTNAME=	magit-1.2.0.50
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/magit/
COMMENT=	Emacs client for (scm)git
LICENSE=	gnu-gpl-v3

GIT_REPOSITORIES=	master
GIT_REPO.master=	https://github.com/magit/magit.git
GIT_MODULE.master=	magit

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

INFO_FILES=		yes
BUILD_TARGET=		all
TEST_TARGET=	check

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
