# $NetBSD: Makefile,v 1.3 2012/09/28 21:24:30 asau Exp $
#

DISTNAME=	darcs-to-git-0.1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://github.com/purcell/${PKGBASE}
COMMENT=	Convert a Darcs repository into a Git repository
LICENSE=	mit

GIT_REPOSITORIES=	master
GIT_REPO.master=	git://github.com/purcell/${PKGBASE}.git
GIT_MODULE.master=	darcs-to-git

WRKSRC=			${WRKDIR}/${PKGBASE}
NO_BUILD=		yes
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	bin share/doc/${DISTNAME}

REPLACE_RUBY_DIRS=	.
REPLACE_RUBY_PAT=	darcs-to-git

DEPENDS+=	scmgit-base-[0-9]*:../../devel/scmgit-base
DEPENDS+=	darcs>1.0.7:../../devel/darcs

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/darcs-to-git    ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA}   ${WRKSRC}/LICENSE         ${DESTDIR}${PREFIX}/share/doc/${DISTNAME}/
	${INSTALL_DATA}   ${WRKSRC}/README.markdown ${DESTDIR}${PREFIX}/share/doc/${DISTNAME}/

.include "../../wip/mk/git-package.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../lang/ruby/replace.mk"
.include "../../mk/bsd.pkg.mk"
