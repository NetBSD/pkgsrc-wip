# $NetBSD$

PKGNAME=		cvs2hg-2.0
CATEGORIES=		devel scm

MAINTAINER=		wiz@NetBSD.org
#HOMEPAGE=		https://www.pkgsrc.org/
COMMENT=		Convert CVS repository to Mercurial
LICENSE=		2-clause-bsd

DEPENDS+=		cvs2fossil-[0-9]*:../../wip/cvs2fossil
DEPENDS+=		${PYPKGPREFIX}-mercurial-[0-9]*:../../devel/py-mercurial
DEPENDS+=		${PYPKGPREFIX}-hg-fastimport-[0-9]*:../../devel/py-hg-fastimport

WRKSRC=			${WRKDIR}
USE_LANGUAGES=		# empty
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-extract:
	${CP} ${FILESDIR}/cvs2hg ${WRKSRC}
	${CP} ${FILESDIR}/cvs2hg.1 ${WRKSRC}

do-configure:

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/cvs2hg ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/cvs2hg.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
