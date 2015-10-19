# $NetBSD$

DISTNAME=	setconf-0.6.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=xyproto/}
GITHUB_PROJECT=	setconf

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://setconf.roboticoverlords.org/
COMMENT=	Small utility to change settings in configuration textfiles
LICENSE=	gnu-gpl-v2

SUBST_CLASSES+=		path
SUBST_SED.path=		-e "s,/usr/bin/python2,${PYTHONBIN},"
SUBST_MESSAGE.path=	Fixing path to python.
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	setconf.py

WRKSRC=	${WRKDIR}/setconf-${PKGVERSION_NOREV}

NO_CONFIGURE=	yes
NO_BUILD=	yes

AUTO_MKDIRS=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/setconf.py ${DESTDIR}${PREFIX}/bin/setconf
	${INSTALL_MAN} ${WRKSRC}/setconf.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
