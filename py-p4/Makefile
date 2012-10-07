# $NetBSD: Makefile,v 1.3 2012/10/07 13:57:25 asau Exp $
#

PKGNAME=	${PYPKGPREFIX}-p4-${P4_VER}
DISTNAME=	p4python
DISTFILES=	p4python.tgz
MASTER_SITES=	ftp://ftp.perforce.com/perforce/r10.2/bin.tools/
HOMEPAGE=	http://www.perforce.com/product/components/apis
COMMENT=	Perforce SCM Python API

.include "../../wip/p4/Makefile.common"

USE_LANGUAGES=	c c++
PYTHON_VERSIONS_ACCEPTED=	31 30 27 26
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

PYSETUPARGS+=	--apidir ${BUILDLINK_DIR}/share/examples/p4
EGG_NAME=	${DISTNAME}-${P4_VER}.${P4_VER_PL}

.include "../../wip/p4api/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
