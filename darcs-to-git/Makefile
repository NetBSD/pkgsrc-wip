# $NetBSD: Makefile,v 1.1.1.1 2010/02/10 16:33:59 phonohawk Exp $
#

DISTNAME=	darcs-to-git-0.1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://github.com/purcell/darcs-to-git
COMMENT=	Convert a Darcs repository into a Git repository
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

GIT_REPOSITORIES=	master
GIT_REPO.master=	git://github.com/purcell/darcs-to-git.git

WRKSRC=			${WRKDIR}/darcs-to-git
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
