# $NetBSD: Makefile,v 1.1.1.1 2012/05/30 10:31:33 thomasklausner Exp $

# for egg
DISTNAME=	musicbrainzngs-0.3dev
PKGNAME=	${PYPKGPREFIX}-musicbrainz-ngs-0.3
CATEGORIES=	audio net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alastair/python-musicbrainz-ngs
COMMENT=	Python bindings for Musicbrainz' NGS service
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

PKG_DESTDIR_SUPPORT=	user-destdir

GIT_REPOSITORIES=			python-musicbrainz-ngs
GIT_REPO.python-musicbrainz-ngs=	git://github.com/alastair/python-musicbrainz-ngs.git

WRKSRC=		${WRKDIR}/python-musicbrainz-ngs

.include "../../lang/python/distutils.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
