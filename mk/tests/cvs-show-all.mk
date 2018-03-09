# $NetBSD$

DISTNAME=	pkgbase-1.0
CATEGORIES=	pkgtools

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	https://www.pkgsrc.org/
COMMENT=	Test for show-all-cvs
LICENSE=	2-clause-bsd

NO_CHECKSUM=	yes

CVS_ROOT=		${.CURDIR}/files/repo
CVS_REPOSITORIES=	2017 current
CVS_ROOT.2017=		${CVS_ROOT}
CVS_MODULE.2017=	${CVS_MODULE}
CVS_TAG.2017=		v2017
CVS_ROOT.current=	${CVS_ROOT}
CVS_MODULE.current=	${CVS_MODULE}

.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
