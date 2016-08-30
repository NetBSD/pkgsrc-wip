# $NetBSD: Makefile,v 1.4 2014/01/12 09:43:46 thomasklausner Exp $

PKGNAME=	${PYPKGPREFIX}-p4-${P4_VER}
DISTNAME=	p4python
DISTFILES=	p4python.tgz
MASTER_SITES=	ftp://ftp.perforce.com/perforce/r10.2/bin.tools/
HOMEPAGE=	http://www.perforce.com/product/components/apis
COMMENT=	Perforce SCM Python API

.include "../../wip/p4/Makefile.common"

USE_LANGUAGES=	c c++

PYSETUPARGS+=	--apidir ${BUILDLINK_DIR}/share/examples/p4
EGG_NAME=	${DISTNAME}-${P4_VER}.${P4_VER_PL}

.include "../../wip/p4api/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
