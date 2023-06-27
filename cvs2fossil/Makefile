# $NetBSD$

DISTNAME=	cvs2fossil-20140502
CATEGORIES=	devel scm
MASTER_SITES=	https://www.sonnenberger.org/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.NetBSD.org/github/
COMMENT=	Tool to convert from CVS to fossil
#LICENSE=	2-clause-bsd AND mit

DEPENDS+=	fossil1-[0-9]*:../../wip/fossil1

WRKSRC=		${WRKDIR}/cvs2fossil

INSTALLATION_DIRS+=	bin libexec/cvs2fossil ${PKGMANDIR}/man1

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	convert.sh
SUBST_VARS.prefix=	PREFIX
SUBST_STAGE.prefix=	post-build
SUBST_MESSAGE.prefix=	Fixing PATH in example file.

do-build:
	cd ${WRKSRC} && ./build.sh

do-install:
.for file in 01-import 02-vendorbranches 03-branchtime 04-commit 99-warnings
	${INSTALL_PROGRAM} ${WRKSRC}/${file}/${file} ${DESTDIR}${PREFIX}/libexec/cvs2fossil
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/convert.sh ${DESTDIR}${PREFIX}/bin/cvs2fossil
	${INSTALL_DATA} ${FILESDIR}/cvs2fossil.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
