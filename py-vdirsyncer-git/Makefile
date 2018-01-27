# $NetBSD: Makefile,v 1.4 2015/08/16 10:45:09 thomasklausner Exp $

DISTNAME=	vdirsyncer-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_PYPI:=v/vdirsyncer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/vdirsyncer/
COMMENT=	Synchronization tool for vdir
LICENSE=	mit

GIT_REPOSITORIES=	vdirsyncer
GIT_REPO.vdirsyncer=	git://github.com/untitaker/vdirsyncer.git

WRKSRC=			${WRKDIR}/vdirsyncer

EXTRACT_USING=	bsdtar	# gtar cannot handle pre-1970 timestamps

DEPENDS+=	${PYPKGPREFIX}-atomicwrites-[0-9]*:../../devel/py-atomicwrites
DEPENDS+=	${PYPKGPREFIX}-click>=2.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-icalendar>=3.6:../../time/py-icalendar
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt>=0.3.0:../../devel/py-requests-toolbelt
# optional, but recommended
DEPENDS+=	${PYPKGPREFIX}-keyring-[0-9]*:../../security/py-keyring

USE_LANGUAGES=		# none
INSTALLATION_DIRS=	share/examples/${PKGBASE}
PLIST_SUBST+=		PKGBASE=${PKGBASE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/example.cfg ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}/

.include "../../lang/python/egg.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
