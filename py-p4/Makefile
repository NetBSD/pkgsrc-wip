# $NetBSD: Makefile,v 1.1.1.1 2011/07/06 10:12:56 bubuchka Exp $
#

PKGNAME=	${PYPKGPREFIX}-p4-${P4_VER}
DISTNAME=	p4python
DISTFILES=	p4python.tgz
MASTER_SITES=	ftp://ftp.perforce.com/perforce/r10.2/bin.tools/
HOMEPAGE=	http://www.perforce.com/perforce/loadsupp.html
COMMENT=	Perforce SCM Python API

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../wip/p4/Makefile.common"

USE_LANGUAGES=	c c++
PYTHON_VERSIONS_ACCEPTED=	31 30 27 26
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

PYSETUPARGS+=	--apidir ${BUILDLINK_DIR}/share/examples/p4
EGG_NAME=	${DISTNAME}-${P4_VER}.${P4_VER_PL}

.include "../../wip/p4api/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
