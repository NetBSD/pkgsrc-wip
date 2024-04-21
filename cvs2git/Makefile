# $NetBSD$

PKGNAME=		cvs2git-3.0
CATEGORIES=		devel scm

MAINTAINER=		wiz@NetBSD.org
#HOMEPAGE=		https://www.pkgsrc.org/
COMMENT=		Convert CVS repository to git
LICENSE=		2-clause-bsd

DEPENDS+=		cvs2fossil-[0-9]*:../../wip/cvs2fossil
DEPENDS+=		git-base-[0-9]*:../../devel/git-base
DEPENDS+=		git-filter-repo-[0-9]*:../../devel/git-filter-repo

WRKSRC=			${WRKDIR}
USE_LANGUAGES=		# empty
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

PYTHON_VERSIONS_INCOMPATIBLE=	27
REPLACE_PYTHON+=		cvs2git

post-extract:
	${CP} ${FILESDIR}/cvs2git ${WRKSRC}
	${CP} ${FILESDIR}/cvs2git.1 ${WRKSRC}

do-configure:

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/cvs2git ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/cvs2git.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
